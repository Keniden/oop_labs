
#ifndef FIGURE_H
#define FIGURE_H

#include "Point.h"
#include <memory>

template <Scalar T>
class Figure {
public:
    virtual void Print() const = 0;
    virtual double Area() const = 0;
    virtual Point<T> Center() const = 0;

    virtual ~Figure() {}

    virtual std::shared_ptr<Figure<T>> Clone() const = 0;

    virtual bool operator==(const Figure& other) const = 0;

    virtual operator double() const = 0;
};

#endif
