#ifndef PENTAGON_H
#define PENTAGON_H

#include "Figure.h"

class Pentagon : public Figure
{
private:
    std::pair<double, double> vertices[5];

public:
    Pentagon();
    Pentagon(const std::pair<double, double> verts[5]);
    Pentagon(const Pentagon &other);
    Pentagon(Pentagon &&other) noexcept;
    ~Pentagon();

    Figure &operator=(const Figure &other) override;
    bool operator==(const Figure &other) const override;

    Pentagon &operator=(const Pentagon &other);
    Pentagon &operator=(Pentagon &&other) noexcept;
    bool operator==(const Pentagon &other) const;
    bool isRegular(double epsilon = 1e-6) const;

    void Print() const override;
    double Area() const override;
    std::pair<double, double> Center() const override;

    operator double() const override;

    Figure *Clone() const override;

    friend std::ostream &operator<<(std::ostream &os, const Pentagon &p);
    friend std::istream &operator>>(std::istream &is, Pentagon &p);
};

#endif
