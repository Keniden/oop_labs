#include "../include/Octagon.h"
#include <cmath>
#include <typeinfo>
#include <iostream>
#include <utility>

Octagon::Octagon()
{
    for (int i = 0; i < 8; ++i)
    {
        vertices[i] = {0.0, 0.0};
    }
}

Octagon::Octagon(const std::pair<double, double> verts[8])
{
    for (int i = 0; i < 8; ++i)
    {
        vertices[i] = verts[i];
    }
    if (!isRegular())
    {
        std::cerr << "cоздан неправильный восьмиугольник.\n";
    }
}

Octagon::Octagon(const Octagon &other)
{
    for (int i = 0; i < 8; ++i)
    {
        vertices[i] = other.vertices[i];
    }
}

Octagon::Octagon(Octagon &&other) noexcept
{
    for (int i = 0; i < 8; ++i)
    {
        vertices[i] = std::move(other.vertices[i]);
    }
}

Octagon::~Octagon() {}

Octagon &Octagon::operator=(const Octagon &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 8; ++i)
        {
            vertices[i] = other.vertices[i];
        }
    }
    return *this;
}

Octagon &Octagon::operator=(Octagon &&other) noexcept
{
    if (this != &other)
    {
        for (int i = 0; i < 8; ++i)
        {
            vertices[i] = std::move(other.vertices[i]);
        }
    }
    return *this;
}

Figure &Octagon::operator=(const Figure &other)
{
    if (this != &other)
    {
        if (typeid(*this) == typeid(other))
        {
            const Octagon &octagon = dynamic_cast<const Octagon &>(other);
            *this = octagon;
        }
        else
        {
            std::cerr << "типы не совпадают\n";
        }
    }
    return *this;
}

bool Octagon::operator==(const Octagon &other) const
{
    for (int i = 0; i < 8; ++i)
    {
        if (vertices[i] != other.vertices[i])
        {
            return false;
        }
    }
    return true;
}

bool Octagon::operator==(const Figure &other) const
{
    if (typeid(*this) != typeid(other))
    {
        return false;
    }
    const Octagon &octagon = dynamic_cast<const Octagon &>(other);
    return *this == octagon;
}

bool Octagon::isRegular(double epsilon) const
{
    double side_length = 0.0;
    for (int i = 0; i < 8; ++i)
    {
        int j = (i + 1) % 8;
        double nx = vertices[j].first - vertices[i].first;
        double ny = vertices[j].second - vertices[i].second;
        double length = std::sqrt(nx * nx + ny * ny);
        if (i == 0)
        {
            side_length = length;
        }
        else
        {
            if (std::abs(length - side_length) > epsilon)
                return false;
        }
    }
    return true;
}

void Octagon::Print() const
{
    std::cout << "вершины:\n";
    for (int i = 0; i < 8; ++i)
    {
        std::cout << "(" << vertices[i].first << ", " << vertices[i].second << ")\n";
    }
}

double Octagon::Area() const
{
    double area = 0.0;
    for (int i = 0; i < 8; ++i)
    {
        const auto &[x1, y1] = vertices[i];
        const auto &[x2, y2] = vertices[(i + 1) % 8];
        area += (x1 * y2 - x2 * y1);
    }
    return std::abs(area) / 2.0;
}

std::pair<double, double> Octagon::Center() const
{
    double x_sum = 0.0;
    double y_sum = 0.0;
    for (int i = 0; i < 8; ++i)
    {
        x_sum += vertices[i].first;
        y_sum += vertices[i].second;
    }
    return {x_sum / 8, y_sum / 8};
}

Octagon::operator double() const
{
    return this->Area();
}

Figure *Octagon::Clone() const
{
    return new Octagon(*this);
}

std::ostream &operator<<(std::ostream &os, const Octagon &o)
{
    for (int i = 0; i < 8; ++i)
    {
        os << o.vertices[i].first << " " << o.vertices[i].second << " ";
    }
    return os;
}

std::istream &operator>>(std::istream &is, Octagon &o)
{
    for (int i = 0; i < 8; ++i)
    {
        is >> o.vertices[i].first >> o.vertices[i].second;
    }
    return is;
}
