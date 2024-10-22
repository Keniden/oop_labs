#include "../include/FigureArray.h"
#include <iostream>

FigureArray::FigureArray() : data(nullptr), capacity(0), size(0) {}

FigureArray::FigureArray(const FigureArray &other) : capacity(other.capacity), size(other.size)
{
    data = new Figure *[capacity];
    for (size_t i = 0; i < size; ++i)
    {
        data[i] = other.data[i]->Clone();
    }
}

FigureArray::FigureArray(FigureArray &&other) noexcept
    : data(other.data), capacity(other.capacity), size(other.size)
{
    other.data = nullptr;
    other.capacity = 0;
    other.size = 0;
}

FigureArray::~FigureArray()
{
    for (size_t i = 0; i < size; ++i)
    {
        delete data[i];
    }
    delete[] data;
}

FigureArray &FigureArray::operator=(const FigureArray &other)
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

FigureArray &FigureArray::operator=(FigureArray &&other) noexcept
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

void FigureArray::resize(size_t new_capacity)
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

void FigureArray::push_back(Figure *figure)
{
    if (size == capacity)
    {
        size_t new_capacity = (capacity == 0) ? 1 : capacity * 2;
        resize(new_capacity);
    }
    data[size++] = figure;
}

void FigureArray::removeAt(size_t index)
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

Figure *FigureArray::operator[](size_t index) const
{
    if (index >= size)
    {
        std::cerr << "неправильный индекс\n";
        return nullptr;
    }
    return data[index];
}

size_t FigureArray::getSize() const
{
    return size;
}

double FigureArray::totalArea() const
{
    double total = 0.0;
    for (size_t i = 0; i < size; ++i)
    {
        total += data[i]->Area();
    }
    return total;
}

void FigureArray::printAll() const
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
