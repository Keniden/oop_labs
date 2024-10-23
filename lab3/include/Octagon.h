#ifndef OCTAGON_H
#define OCTAGON_H

#include "Figure.h"

class Octagon : public Figure
{
private:
    std::pair<double, double> vertices[8];

public:
    Octagon();
    Octagon(const std::pair<double, double> verts[8]);
    Octagon(const Octagon &other);
    Octagon(Octagon &&other) noexcept;
    ~Octagon();

    Figure &operator=(const Figure &other) override;
    bool operator==(const Figure &other) const override;

    Octagon &operator=(const Octagon &other);
    Octagon &operator=(Octagon &&other) noexcept;
    bool operator==(const Octagon &other) const;
    bool isRegular(double epsilon = 1e-6) const;

    void Print() const override;
    double Area() const override;
    std::pair<double, double> Center() const override;

    operator double() const override;

    Figure *Clone() const override;

    friend std::ostream &operator<<(std::ostream &os, const Octagon &o);
    friend std::istream &operator>>(std::istream &is, Octagon &o);
};

#endif
