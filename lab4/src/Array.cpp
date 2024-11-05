#include "../include/Array.h"
#include <iostream>

Array::Array() : data(nullptr), capacity(0), size(0) {}

Array::Array(const Array &other) : capacity(other.capacity), size(other.size)
{
    data = new Figure *[capacity];
    for (size_t i = 0; i < size; ++i)
    {
        data[i] = other.data[i]->Clone();
    }
}

Array::Array(Array &&other) noexcept
    : data(other.data), capacity(other.capacity), size(other.size)
{
    other.data = nullptr;
    other.capacity = 0;
    other.size = 0;
}

Array::~Array()
{
    for (size_t i = 0; i < size; ++i)
    {
        delete data[i];
    }
    delete[] data;
}

Array &Array::operator=(const Array &other)
{
    if (this != &other)
    {
        for (size_t i = 0; i < size; ++i)
        {
            delete data[i];
        }
        delete[] data;

        capacity = other.capacity;
        size = other.size;
        data = new Figure *[capacity];
        for (size_t i = 0; i < size; ++i)
        {
            data[i] = other.data[i]->Clone(); 
        }
    }
    return *this;
}

Array &Array::operator=(Array &&other) noexcept
{
    if (this != &other)
    {
        for (size_t i = 0; i < size; ++i)
        {
            delete data[i];
        }
        delete[] data;

        data = other.data;
        capacity = other.capacity;
        size = other.size;

        other.data = nullptr;
        other.capacity = 0;
        other.size = 0;
    }
    return *this;
}

void Array::resize(size_t new_capacity)
{
    Figure **new_data = new Figure *[new_capacity];
    for (size_t i = 0; i < size; ++i)
    {
        new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;
    capacity = new_capacity;
}

void Array::push_back(Figure *figure)
{
    if (size == capacity)
    {
        size_t new_capacity = (capacity == 0) ? 1 : capacity * 2;
        resize(new_capacity);
    }
    data[size++] = figure;
}

void Array::removeAt(size_t index)
{
    if (index >= size)
    {
        std::cerr << "неправильный индекс\n";
        return;
    }
    delete data[index];
    for (size_t i = index; i < size - 1; ++i)
    {
        data[i] = data[i + 1];
    }
    --size;
}

Figure *Array::operator[](size_t index) const
{
    if (index >= size)
    {
        std::cerr << "неправильный индекс\n";
        return nullptr;
    }
    return data[index];
}

size_t Array::getSize() const
{
    return size;
}

double Array::totalArea() const
{
    double total = 0.0;
    for (size_t i = 0; i < size; ++i)
    {
        total += data[i]->Area();
    }
    return total;
}

void Array::printAll() const
{
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << "Figure #" << i << ":\n";
        data[i]->Print();
        auto center = data[i]->Center();
        std::cout << "Center: (" << center.first << ", " << center.second << ")\n";
        std::cout << "Area: " << data[i]->Area() << "\n";
    }
}
