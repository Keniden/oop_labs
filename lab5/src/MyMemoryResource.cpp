#include "MyMemoryResource.hpp"
#include <new>

void* MyMemoryResource::do_allocate(size_t bytes, size_t alignment) {
    for (auto it = free_blocks.lower_bound(bytes); it != free_blocks.end(); ++it) {
        if (it->first >= bytes) {
            void* p = it->second;
            free_blocks.erase(it);
            allocated_blocks[p] = bytes;
            return p;
        }
    }
    void* p = ::operator new(bytes, std::align_val_t(alignment));
    allocated_blocks[p] = bytes;
    return p;
}

void MyMemoryResource::do_deallocate(void* p, size_t bytes, size_t alignment) {
    auto it = allocated_blocks.find(p);
    if (it != allocated_blocks.end()) {
        size_t block_size = it->second;
        allocated_blocks.erase(it);
        free_blocks.insert(std::make_pair(block_size, p));
    }
}

bool MyMemoryResource::do_is_equal(const std::pmr::memory_resource& other) const noexcept {
    return this == &other;
}

MyMemoryResource::~MyMemoryResource() {
    for (auto& pair : allocated_blocks) {
        ::operator delete(pair.first, std::align_val_t(alignof(std::max_align_t)));
    }
    for (auto& pair : free_blocks) {
        ::operator delete(pair.second, std::align_val_t(alignof(std::max_align_t)));
    }
}
