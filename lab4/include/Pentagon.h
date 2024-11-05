// Pentagon.h
#ifndef PENTAGON_H
#define PENTAGON_H

#include "Figure.h"
#include <array>
#include <memory>
#include <cmath>

template <Scalar T>
class Pentagon : public Figure<T> {
private:
    std::array<std::unique_ptr<Point<T>>, 5> vertices;

public:
    Pentagon() {
        for (auto& vertex : vertices) {
            vertex = std::make_unique<Point<T>>();
        }
    }

    Pentagon(const std::array<Point<T>, 5>& points) {
        for (size_t i = 0; i < 5; ++i) {
            vertices[i] = std::make_unique<Point<T>>(points[i]);
        }
    }

    Pentagon(const Pentagon& other) {
        for (size_t i = 0; i < 5; ++i) {
            vertices[i] = std::make_unique<Point<T>>(*(other.vertices[i]));
        }
    }

    Pentagon(Pentagon&& other) noexcept {
        for (size_t i = 0; i < 5; ++i) {
            vertices[i] = std::move(other.vertices[i]);
        }
    }

    Pentagon& operator=(const Pentagon& other) {
        if (this != &other) {
            for (size_t i = 0; i < 5; ++i) {
                vertices[i] = std::make_unique<Point<T>>(*(other.vertices[i]));
            }
        }
        return *this;
    }

    Pentagon& operator=(Pentagon&& other) noexcept {
        if (this != &other) {
            for (size_t i = 0; i < 5; ++i) {
                vertices[i] = std::move(other.vertices[i]);
            }
        }
        return *this;
    }

    void Print() const override {
        std::cout << "Pentagon vertices:\n";
        for (const auto& vertex : vertices) {
            std::cout << *vertex << "\n";
        }
    }

    double Area() const override {
        double area = 0.0;
        for (size_t i = 0; i < 5; ++i) {
            T x1 = vertices[i]->x;
            T y1 = vertices[i]->y;
            T x2 = vertices[(i + 1) % 5]->x;
            T y2 = vertices[(i + 1) % 5]->y;
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
        return Point<T>(x_sum / 5, y_sum / 5);
    }

    bool operator==(const Figure<T>& other) const override {
        const Pentagon<T>* pent = dynamic_cast<const Pentagon<T>*>(&other);
        if (!pent) return false;
        for (size_t i = 0; i < 5; ++i) {
            if (*(vertices[i]) != *(pent->vertices[i])) {
                return false;
            }
        }
        return true;
    }

    operator double() const override {
        return Area();
    }

    std::shared_ptr<Figure<T>> Clone() const override {
        return std::make_shared<Pentagon<T>>(*this);
    }

    friend std::istream& operator>>(std::istream& is, Pentagon& p) {
        for (auto& vertex : p.vertices) {
            vertex = std::make_unique<Point<T>>();
            is >> *(vertex);
        }
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Pentagon& p) {
        for (const auto& vertex : p.vertices) {
            os << *vertex << " ";
        }
        return os;
    }
};

#endif
