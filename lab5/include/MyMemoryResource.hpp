#ifndef MY_MEMORY_RESOURCE_HPP
#define MY_MEMORY_RESOURCE_HPP

#include <memory_resource>
#include <map>
#include <cstddef>
#include <new>

class MyMemoryResource : public std::pmr::memory_resource {
private:
    std::map<void*, size_t> allocated_blocks;
    std::multimap<size_t, void*> free_blocks;

protected:
    void* do_allocate(size_t bytes, size_t alignment) override;
    void do_deallocate(void* p, size_t bytes, size_t alignment) override;
    bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override;

public:
    ~MyMemoryResource();
};

#endif
