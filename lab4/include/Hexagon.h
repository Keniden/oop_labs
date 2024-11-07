#ifndef HEXAGON_H
#define HEXAGON_H

#include "Figure.h"
#include <array>
#include <memory>

template <Scalar T>
class Hexagon : public Figure<T> {
private:
    std::array<std::unique_ptr<Point<T>>, 6> vertices;

public:
    Hexagon();
    Hexagon(const std::array<Point<T>, 6>& points);

    Hexagon(const Hexagon& other);
    Hexagon(Hexagon&& other) noexcept;

    Hexagon& operator=(const Hexagon& other);
    Hexagon& operator=(Hexagon&& other) noexcept;

    void Print() const override;
    double Area() const override;
    Point<T> Center() const override;

    bool operator==(const Hexagon<T>& other) const;
    bool operator==(const Figure<T>& other) const override;

    operator double() const override;

    std::shared_ptr<Figure<T>> Clone() const override;

    template <Scalar U>
    friend std::istream& operator>>(std::istream& is, Hexagon<U>& h);

    template <Scalar U>
    friend std::ostream& operator<<(std::ostream& os, const Hexagon<U>& h);
};

#endif // HEXAGON_H
