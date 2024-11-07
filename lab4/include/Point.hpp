#ifndef POINT_HPP
#define POINT_HPP

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

    Point();
    Point(T x_coord, T y_coord);

    Point(const Point& other);
    Point(Point&& other) noexcept;

    Point& operator=(const Point& other);
    Point& operator=(Point&& other) noexcept;

    bool operator==(const Point& other) const;

    template <Scalar U>
    friend std::ostream& operator<<(std::ostream& os, const Point<U>& p);

    template <Scalar U>
    friend std::istream& operator>>(std::istream& is, Point<U>& p);
};

#include "Point.tpp"

#endif // POINT_HPP
