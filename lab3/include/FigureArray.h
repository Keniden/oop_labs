#ifndef FIGUREARRAY_H
#define FIGUREARRAY_H

#include "Figure.h"
#include <cstddef>

class FigureArray
{
private:
    Figure **data;
    size_t capacity;
    size_t size;

    void resize(size_t new_capacity);

public:
    FigureArray();
    FigureArray(const FigureArray &other);
    FigureArray(FigureArray &&other) noexcept;
    ~FigureArray();

    FigureArray &operator=(const FigureArray &other);
    FigureArray &operator=(FigureArray &&other) noexcept;

    Figure *operator[](size_t index) const;
    size_t getSize() const;

    void push_back(Figure *figure);
    void removeAt(size_t index);

    double totalArea() const;
    void printAll() const;
};

#endif
