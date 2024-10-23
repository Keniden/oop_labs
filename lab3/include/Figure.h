#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <utility>

class Figure
{
public:
    virtual void Print() const = 0;
    virtual double Area() const = 0;
    virtual std::pair<double, double> Center() const = 0;
    virtual ~Figure() {}

    virtual Figure &operator=(const Figure &other) = 0;
    virtual bool operator==(const Figure &other) const = 0;

    virtual operator double() const = 0;

    virtual Figure *Clone() const = 0;
};

#endif
