// Octagon.h
#ifndef OCTAGON_H
#define OCTAGON_H

#include "Figure.h"
#include <array>
#include <memory>
#include <cmath>

template <Scalar T>
class Octagon : public Figure<T> {
private:
    std::array<std::unique_ptr<Point<T>>, 8> vertices;

public:
    Octagon() {
        for (auto& vertex : vertices) {
            vertex = std::make_unique<Point<T>>();
        }
    }

    Octagon(const std::array<Point<T>, 8>& points) {
        for (size_t i = 0; i < 8; ++i) {
            vertices[i] = std::make_unique<Point<T>>(points[i]);
        }
    }

    Octagon(const Octagon& other) {
        for (size_t i = 0; i < 8; ++i) {
            vertices[i] = std::make_unique<Point<T>>(*(other.vertices[i]));
        }
    }

    Octagon(Octagon&& other) noexcept {
        for (size_t i = 0; i < 8; ++i) {
            vertices[i] = std::move(other.vertices[i]);
        }
    }

    Octagon& operator=(const Octagon& other) {
        if (this != &other) {
            for (size_t i = 0; i < 8; ++i) {
                vertices[i] = std::make_unique<Point<T>>(*(other.vertices[i]));
            }
        }
        return *this;
    }

    Octagon& operator=(Octagon&& other) noexcept {
        if (this != &other) {
            for (size_t i = 0; i < 8; ++i) {
                vertices[i] = std::move(other.vertices[i]);
            }
        }
        return *this;
    }

    void Print() const override {
        std::cout << "Octagon vertices:\n";
        for (const auto& vertex : vertices) {
            std::cout << *vertex << "\n";
        }
    }

    double Area() const override {
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

    Point<T> Center() const override {
        T x_sum = 0;
        T y_sum = 0;
        for (const auto& vertex : vertices) {
            x_sum += vertex->x;
            y_sum += vertex->y;
        }
        return Point<T>(x_sum / 8, y_sum / 8);
    }

    bool operator==(const Octagon<T>& other) const {
        for (size_t i = 0; i < 8; ++i) {
            if (*(vertices[i]) != *(other.vertices[i])) {
                return false;
            }
        }
        return true;
    }

    bool operator==(const Figure<T>& other) const override {
        const Octagon<T>* oct = dynamic_cast<const Octagon<T>*>(&other);
        if (!oct) return false;
        return *this == *oct;
    }

    operator double() const override {
        return Area();
    }

    std::shared_ptr<Figure<T>> Clone() const override {
        return std::make_shared<Octagon<T>>(*this);
    }

    friend std::istream& operator>>(std::istream& is, Octagon& o) {
        for (auto& vertex : o.vertices) {
            vertex = std::make_unique<Point<T>>();
            is >> *(vertex);
        }
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Octagon& o) {
        for (const auto& vertex : o.vertices) {
            os << *vertex << " ";
        }
        return os;
    }
};

#endif
