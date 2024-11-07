#include "Octagon.h"
#include <iostream>
#include <cmath>

template <Scalar T>
Octagon<T>::Octagon() {
    for (auto& vertex : vertices) {
        vertex = std::make_unique<Point<T>>();
    }
}

template <Scalar T>
Octagon<T>::Octagon(const std::array<Point<T>, 8>& points) {
    for (size_t i = 0; i < 8; ++i) {
        vertices[i] = std::make_unique<Point<T>>(points[i]);
    }
}

template <Scalar T>
Octagon<T>::Octagon(const Octagon& other) {
    for (size_t i = 0; i < 8; ++i) {
        vertices[i] = std::make_unique<Point<T>>(*(other.vertices[i]));
    }
}

template <Scalar T>
Octagon<T>::Octagon(Octagon&& other) noexcept {
    for (size_t i = 0; i < 8; ++i) {
        vertices[i] = std::move(other.vertices[i]);
    }
}

template <Scalar T>
Octagon<T>& Octagon<T>::operator=(const Octagon& other) {
    if (this != &other) {
        for (size_t i = 0; i < 8; ++i) {
            vertices[i] = std::make_unique<Point<T>>(*(other.vertices[i]));
        }
    }
    return *this;
}

template <Scalar T>
Octagon<T>& Octagon<T>::operator=(Octagon&& other) noexcept {
    if (this != &other) {
        for (size_t i = 0; i < 8; ++i) {
            vertices[i] = std::move(other.vertices[i]);
        }
    }
    return *this;
}

template <Scalar T>
void Octagon<T>::Print() const {
    std::cout << "Octagon vertices:\n";
    for (const auto& vertex : vertices) {
        std::cout << *vertex << "\n";
    }
}

template <Scalar T>
double Octagon<T>::Area() const {
    double area = 0.0;
    for (size_t i = 0; i < 8; ++i) {
        T x1 = vertices[i]->x;
        T y1 = vertices[i]->y;
        T x2 = vertices[(i + 1) % 8]->x;
        T y2 = vertices[(i + 1) % 8]->y;
        area += static_cast<double>(x1 * y2 - x2 * y1);
    }
    return std::abs(area) / 2.0;
}

template <Scalar T>
Point<T> Octagon<T>::Center() const {
    T x_sum = 0;
    T y_sum = 0;
    for (const auto& vertex : vertices) {
        x_sum += vertex->x;
        y_sum += vertex->y;
    }
    return Point<T>(x_sum / 8, y_sum / 8);
}

template <Scalar T>
bool Octagon<T>::operator==(const Octagon<T>& other) const {
    for (size_t i = 0; i < 8; ++i) {
        if (*(this->vertices[i]) != *(other.vertices[i])) {
            return false;
        }
    }
    return true;
}

template <Scalar T>
bool Octagon<T>::operator==(const Figure<T>& other) const {
    const Octagon<T>* oct = dynamic_cast<const Octagon<T>*>(&other);
    if (!oct) return false;
    return *this == *oct;
}

template <Scalar T>
Octagon<T>::operator double() const {
    return Area();
}

template <Scalar T>
std::shared_ptr<Figure<T>> Octagon<T>::Clone() const {
    return std::make_shared<Octagon<T>>(*this);
}

template <Scalar T>
std::istream& operator>>(std::istream& is, Octagon<T>& o) {
    for (auto& vertex : o.vertices) {
        vertex = std::make_unique<Point<T>>();
        is >> *(vertex);
    }
    return is;
}

template <Scalar T>
std::ostream& operator<<(std::ostream& os, const Octagon<T>& o) {
    for (const auto& vertex : o.vertices) {
        os << *vertex << " ";
    }
    return os;
}

template class Octagon<int>;
template class Octagon<float>;
template class Octagon<double>;

template std::istream& operator>>(std::istream& is, Octagon<int>& o);
template std::istream& operator>>(std::istream& is, Octagon<float>& o);
template std::istream& operator>>(std::istream& is, Octagon<double>& o);

template std::ostream& operator<<(std::ostream& os, const Octagon<int>& o);
template std::ostream& operator<<(std::ostream& os, const Octagon<float>& o);
template std::ostream& operator<<(std::ostream& os, const Octagon<double>& o);
