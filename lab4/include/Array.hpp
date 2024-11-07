#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <memory>
#include <stdexcept>

template <class T>
class Array {
private:
    std::shared_ptr<T[]> data;
    size_t capacity;
    size_t size;

    void resize(size_t new_capacity);

public:
    Array();

    Array(const Array& other);
    Array(Array&& other) noexcept;

    Array& operator=(const Array& other);
    Array& operator=(Array&& other) noexcept;

    void push_back(const T& element);

    void removeAt(size_t index);

    T& operator[](size_t index) const;

    size_t getSize() const;

    T* begin() const;
    T* end() const;
};

#include "Array.tpp"

#endif // ARRAY_HPP
