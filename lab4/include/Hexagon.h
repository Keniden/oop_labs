// Hexagon.h
#ifndef HEXAGON_H
#define HEXAGON_H

#include "Figure.h"
#include <array>
#include <memory>
#include <cmath>

template <Scalar T>
class Hexagon : public Figure<T> {
private:
    std::array<std::unique_ptr<Point<T>>, 6> vertices;

public:
    Hexagon() {
        for (auto& vertex : vertices) {
            vertex = std::make_unique<Point<T>>();
        }
    }

    Hexagon(const std::array<Point<T>, 6>& points) {
        for (size_t i = 0; i < 6; ++i) {
            vertices[i] = std::make_unique<Point<T>>(points[i]);
        }
    }

    Hexagon(const Hexagon& other) {
        for (size_t i = 0; i < 6; ++i) {
            vertices[i] = std::make_unique<Point<T>>(*(other.vertices[i]));
        }
    }

    Hexagon(Hexagon&& other) noexcept {
        for (size_t i = 0; i < 6; ++i) {
            vertices[i] = std::move(other.vertices[i]);
        }
    }

    Hexagon& operator=(const Hexagon& other) {
        if (this != &other) {
            for (size_t i = 0; i < 6; ++i) {
                vertices[i] = std::make_unique<Point<T>>(*(other.vertices[i]));
            }
        }
        return *this;
    }

    Hexagon& operator=(Hexagon&& other) noexcept {
        if (this != &other) {
            for (size_t i = 0; i < 6; ++i) {
                vertices[i] = std::move(other.vertices[i]);
            }
        }
        return *this;
    }

    void Print() const override {
        std::cout << "Hexagon vertices:\n";
        for (const auto& vertex : vertices) {
            std::cout << *vertex << "\n";
        }
    }

    double Area() const override {
        double area = 0.0;
        for (size_t i = 0; i < 6; ++i) {
            T x1 = vertices[i]->x;
            T y1 = vertices[i]->y;
            T x2 = vertices[(i + 1) % 6]->x;
            T y2 = vertices[(i + 1) % 6]->y;
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
        return Point<T>(x_sum / 6, y_sum / 6);
    }

    bool operator==(const Hexagon<T>& other) const {
        for (size_t i = 0; i < 6; ++i) {
            if (*(vertices[i]) != *(other.vertices[i])) {
                return false;
            }
        }
        return true;
    }

    bool operator==(const Figure<T>& other) const override {
        const Hexagon<T>* hex = dynamic_cast<const Hexagon<T>*>(&other);
        if (!hex) return false;
        return *this == *hex;
    }

    operator double() const override {
        return Area();
    }

    std::shared_ptr<Figure<T>> Clone() const override {
        return std::make_shared<Hexagon<T>>(*this);
    }

    friend std::istream& operator>>(std::istream& is, Hexagon& h) {
        for (auto& vertex : h.vertices) {
            vertex = std::make_unique<Point<T>>();
            is >> *(vertex);
        }
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Hexagon& h) {
        for (const auto& vertex : h.vertices) {
            os << *vertex << " ";
        }
        return os;
    }
};

#endif
