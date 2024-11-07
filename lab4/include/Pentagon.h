#ifndef PENTAGON_H
#define PENTAGON_H

#include "Figure.h"
#include <array>
#include <memory>

template <Scalar T>
class Pentagon : public Figure<T> {
private:
    std::array<std::unique_ptr<Point<T>>, 5> vertices;

public:
    Pentagon();
    Pentagon(const std::array<Point<T>, 5>& points);

    Pentagon(const Pentagon& other);
    Pentagon(Pentagon&& other) noexcept;

    Pentagon& operator=(const Pentagon& other);
    Pentagon& operator=(Pentagon&& other) noexcept;

    void Print() const override;
    double Area() const override;
    Point<T> Center() const override;

    bool operator==(const Pentagon<T>& other) const;
    bool operator==(const Figure<T>& other) const override;

    operator double() const override;

    std::shared_ptr<Figure<T>> Clone() const override;

    template <Scalar U>
    friend std::istream& operator>>(std::istream& is, Pentagon<U>& p);

    template <Scalar U>
    friend std::ostream& operator<<(std::ostream& os, const Pentagon<U>& p);
};

#endif // PENTAGON_H
