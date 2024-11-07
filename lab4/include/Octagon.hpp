#ifndef OCTAGON_HPP
#define OCTAGON_HPP

#include "Figure.hpp"
#include <array>
#include <memory>

template <Scalar T>
class Octagon : public Figure<T> {
private:
    std::array<std::unique_ptr<Point<T>>, 8> vertices;

public:
    Octagon();
    Octagon(const std::array<Point<T>, 8>& points);

    Octagon(const Octagon& other);
    Octagon(Octagon&& other) noexcept;

    Octagon& operator=(const Octagon& other);
    Octagon& operator=(Octagon&& other) noexcept;

    void Print() const override;
    double Area() const override;
    Point<T> Center() const override;

    bool operator==(const Octagon<T>& other) const;
    bool operator==(const Figure<T>& other) const override;

    operator double() const override;

    std::shared_ptr<Figure<T>> Clone() const override;

    template <Scalar U>
    friend std::istream& operator>>(std::istream& is, Octagon<U>& o);

    template <Scalar U>
    friend std::ostream& operator<<(std::ostream& os, const Octagon<U>& o);
};

#include "Octagon.tpp"

#endif // OCTAGON_HPP
