
#ifndef ARRAY_H
#define ARRAY_H

#include <memory>
#include <stdexcept>

template <class T>
class Array {
private:
    std::shared_ptr<T[]> data;
    size_t capacity;
    size_t size;

    void resize(size_t new_capacity) {
        std::shared_ptr<T[]> new_data(new T[new_capacity], std::default_delete<T[]>());
        for (size_t i = 0; i < size; ++i) {
            new_data[i] = std::move(data[i]);
        }
        data = new_data;
        capacity = new_capacity;
    }

public:
    Array() : data(nullptr), capacity(0), size(0) {}

    Array(const Array& other) : capacity(other.capacity), size(other.size) {
        data = std::shared_ptr<T[]>(new T[capacity], std::default_delete<T[]>());
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    Array(Array&& other) noexcept : data(std::move(other.data)), capacity(other.capacity), size(other.size) {
        other.capacity = 0;
        other.size = 0;
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            data = std::shared_ptr<T[]>(new T[other.capacity], std::default_delete<T[]>());
            capacity = other.capacity;
            size = other.size;
            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    Array& operator=(Array&& other) noexcept {
        if (this != &other) {
            data = std::move(other.data);
            capacity = other.capacity;
            size = other.size;
            other.capacity = 0;
            other.size = 0;
        }
        return *this;
    }

    void push_back(const T& element) {
        if (size == capacity) {
            size_t new_capacity = (capacity == 0) ? 1 : capacity * 2;
            resize(new_capacity);
        }
        data[size++] = element;
    }

    void removeAt(size_t index) {
        if (index >= size) {
            throw std::out_of_range("Неправильный индекс");
        }
        for (size_t i = index; i < size - 1; ++i) {
            data[i] = std::move(data[i + 1]);
        }
        --size;
    }

    T& operator[](size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Неправильный индекс");
        }
        return data[index];
    }

    size_t getSize() const {
        return size;
    }

    T* begin() const {
        return data.get();
    }

    T* end() const {
        return data.get() + size;
    }
};

#endif 
