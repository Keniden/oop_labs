#ifndef HEXAGON_H
#define HEXAGON_H

#include "Figure.h"

class Hexagon : public Figure
{
private:
    std::pair<double, double> vertices[6];

public:
    Hexagon();
    Hexagon(const std::pair<double, double> verts[6]);
    Hexagon(const Hexagon &other);
    Hexagon(Hexagon &&other) noexcept;
    ~Hexagon();

    Figure &operator=(const Figure &other) override;
    bool operator==(const Figure &other) const override;

    Hexagon &operator=(const Hexagon &other);
    Hexagon &operator=(Hexagon &&other) noexcept;
    bool operator==(const Hexagon &other) const;
    bool isRegular(double epsilon = 1e-6) const;

    void Print() const override;
    double Area() const override;
    std::pair<double, double> Center() const override;

    operator double() const override;

    Figure *Clone() const override;

    friend std::ostream &operator<<(std::ostream &os, const Hexagon &h);
    friend std::istream &operator>>(std::istream &is, Hexagon &h);
};

#endif