#include "Point.h"

template <Scalar T>
Point<T>::Point() : x(0), y(0) {}

template <Scalar T>
Point<T>::Point(T x_coord, T y_coord) : x(x_coord), y(y_coord) {}

template <Scalar T>
Point<T>::Point(const Point& other) : x(other.x), y(other.y) {}

template <Scalar T>
Point<T>::Point(Point&& other) noexcept : x(std::move(other.x)), y(std::move(other.y)) {}

template <Scalar T>
Point<T>& Point<T>::operator=(const Point& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

template <Scalar T>
Point<T>& Point<T>::operator=(Point&& other) noexcept {
    if (this != &other) {
        x = std::move(other.x);
        y = std::move(other.y);
    }
    return *this;
}

template <Scalar T>
bool Point<T>::operator==(const Point& other) const {
    return x == other.x && y == other.y;
}

template <Scalar T>
std::ostream& operator<<(std::ostream& os, const Point<T>& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

template <Scalar T>
std::istream& operator>>(std::istream& is, Point<T>& p) {
    is >> p.x >> p.y;
    return is;
}

template class Point<int>;
template class Point<float>;
template class Point<double>;

template std::ostream& operator<<(std::ostream& os, const Point<int>& p);
template std::ostream& operator<<(std::ostream& os, const Point<float>& p);
template std::ostream& operator<<(std::ostream& os, const Point<double>& p);

template std::istream& operator>>(std::istream& is, Point<int>& p);
template std::istream& operator>>(std::istream& is, Point<float>& p);
template std::istream& operator>>(std::istream& is, Point<double>& p);
