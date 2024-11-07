#ifndef MY_VECTOR_HPP
#define MY_VECTOR_HPP

#include <memory_resource>
#include <memory>
#include <iterator>
#include <cstddef>

template <typename T>
class MyVector {
public:
    using allocator_type = std::pmr::polymorphic_allocator<T>;

private:
    T* data_;
    std::size_t size_;
    std::size_t capacity_;
    allocator_type alloc_;

    void reallocate(std::size_t new_capacity) {
        T* new_data = alloc_.allocate(new_capacity);
        for (std::size_t i = 0; i < size_; ++i) {
            std::allocator_traits<allocator_type>::construct(alloc_, &new_data[i], std::move(data_[i]));
            std::allocator_traits<allocator_type>::destroy(alloc_, &data_[i]);
        }
        if (data_) {
            alloc_.deallocate(data_, capacity_);
        }
        data_ = new_data;
        capacity_ = new_capacity;
    }

public:
    MyVector(const allocator_type& alloc = {})
        : data_(nullptr), size_(0), capacity_(0), alloc_(alloc) {}

    ~MyVector() {
        for (std::size_t i = 0; i < size_; ++i) {
            std::allocator_traits<allocator_type>::destroy(alloc_, &data_[i]);
        }
        if (data_) {
            alloc_.deallocate(data_, capacity_);
        }
    }

    std::size_t size() const noexcept { return size_; }
    std::size_t capacity() const noexcept { return capacity_; }
    bool empty() const noexcept { return size_ == 0; }

    void push_back(const T& value) {
        if (size_ == capacity_) {
            reallocate(capacity_ == 0 ? 1 : capacity_ * 2);
        }
        std::allocator_traits<allocator_type>::construct(alloc_, &data_[size_], value);
        ++size_;
    }

    void push_back(T&& value) {
        if (size_ == capacity_) {
            reallocate(capacity_ == 0 ? 1 : capacity_ * 2);
        }
        std::allocator_traits<allocator_type>::construct(alloc_, &data_[size_], std::move(value));
        ++size_;
    }

    void pop_back() {
        if (size_ > 0) {
            --size_;
            std::allocator_traits<allocator_type>::destroy(alloc_, &data_[size_]);
        }
    }

    T& operator[](std::size_t index) { return data_[index]; }
    const T& operator[](std::size_t index) const { return data_[index]; }

    class iterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        iterator(T* ptr = nullptr) : ptr_(ptr) {}

        reference operator*() const { return *ptr_; }
        pointer operator->() const { return ptr_; }

        iterator& operator++() {
            ++ptr_;
            return *this;
        }
        iterator operator++(int) {
            iterator temp = *this;
            ++ptr_;
            return temp;
        }

        bool operator==(const iterator& other) const { return ptr_ == other.ptr_; }
        bool operator!=(const iterator& other) const { return ptr_ != other.ptr_; }

    private:
        T* ptr_;
    };

    iterator begin() { return iterator(data_); }
    iterator end() { return iterator(data_ + size_); }
};

#endif
