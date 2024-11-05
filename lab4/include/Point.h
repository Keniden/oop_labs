// Point.h
#ifndef POINT_H
#define POINT_H

#include <concepts>
#include <iostream>
#include <type_traits>

template <typename T>
concept Scalar = std::is_arithmetic_v<T>;

template <Scalar T>
class Point {
public:
    T x;
    T y;

    Point() : x(0), y(0) {}
    Point(T x_coord, T y_coord) : x(x_coord), y(y_coord) {}

    Point(const Point& other) : x(other.x), y(other.y) {}

    Point(Point&& other) noexcept : x(std::move(other.x)), y(std::move(other.y)) {}

    Point& operator=(const Point& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
        }
        return *this;
    }

    Point& operator=(Point&& other) noexcept {
        if (this != &other) {
            x = std::move(other.x);
            y = std::move(other.y);
        }
        return *this;
    }

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }

    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Point& p) {
        is >> p.x >> p.y;
        return is;
    }
};

#endif
