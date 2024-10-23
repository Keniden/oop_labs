#include "../include/Hexagon.h"
#include <cmath>
#include <typeinfo>
#include <iostream>
#include <utility>

Hexagon::Hexagon()
{
    for (int i = 0; i < 6; ++i)
    {
        vertices[i] = {0.0, 0.0};
    }
}

Hexagon::Hexagon(const std::pair<double, double> verts[6])
{
    for (int i = 0; i < 6; ++i)
    {
        vertices[i] = verts[i];
    }
    if (!isRegular())
    {
        std::cerr << "cоздан неправильный шестиугольник\n";
    }
}

Hexagon::Hexagon(const Hexagon &other)
{
    for (int i = 0; i < 6; ++i)
    {
        vertices[i] = other.vertices[i];
    }
}

Hexagon::Hexagon(Hexagon &&other) noexcept
{
    for (int i = 0; i < 6; ++i)
    {
        vertices[i] = std::move(other.vertices[i]);
    }
}

Hexagon::~Hexagon() {}

Hexagon &Hexagon::operator=(const Hexagon &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 6; ++i)
        {
            vertices[i] = other.vertices[i];
        }
    }
    return *this;
}

Hexagon &Hexagon::operator=(Hexagon &&other) noexcept
{
    if (this != &other)
    {
        for (int i = 0; i < 6; ++i)
        {
            vertices[i] = std::move(other.vertices[i]);
        }
    }
    return *this;
}

Figure &Hexagon::operator=(const Figure &other)
{
    if (this != &other)
    {
        if (typeid(*this) == typeid(other))
        {
            const Hexagon &hexagon = dynamic_cast<const Hexagon &>(other);
            *this = hexagon;
        }
        else
        {
            std::cerr << "типы не совпадают\n";
        }
    }
    return *this;
}

bool Hexagon::operator==(const Hexagon &other) const
{
    for (int i = 0; i < 6; ++i)
    {
        if (vertices[i] != other.vertices[i])
        {
            return false;
        }
    }
    return true;
}

bool Hexagon::operator==(const Figure &other) const
{
    if (typeid(*this) != typeid(other))
    {
        return false;
    }
    const Hexagon &hexagon = dynamic_cast<const Hexagon &>(other);
    return *this == hexagon;
}

bool Hexagon::isRegular(double epsilon) const
{
    
    double side_length = 0.0;
    for (int i = 0; i < 6; ++i)
    {
        int j = (i + 1) % 6;
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

void Hexagon::Print() const
{
    std::cout << "вершины:\n";
    for (int i = 0; i < 6; ++i)
    {
        std::cout << "(" << vertices[i].first << ", " << vertices[i].second << ")\n";
    }
}

double Hexagon::Area() const
{
    double area = 0.0;
    for (int i = 0; i < 6; ++i)
    {
        const auto &[x1, y1] = vertices[i];
        const auto &[x2, y2] = vertices[(i + 1) % 6];
        area += (x1 * y2 - x2 * y1);
    }
    return std::abs(area) / 2.0;
}

std::pair<double, double> Hexagon::Center() const
{
    double x_sum = 0.0;
    double y_sum = 0.0;
    for (int i = 0; i < 6; ++i)
    {
        x_sum += vertices[i].first;
        y_sum += vertices[i].second;
    }
    return {x_sum / 6, y_sum / 6};
}

Hexagon::operator double() const
{
    return this->Area();
}

Figure *Hexagon::Clone() const
{
    return new Hexagon(*this);
}

std::ostream &operator<<(std::ostream &os, const Hexagon &h)
{
    for (int i = 0; i < 6; ++i)
    {
        os << h.vertices[i].first << " " << h.vertices[i].second << " ";
    }
    return os;
}

std::istream &operator>>(std::istream &is, Hexagon &h)
{
    for (int i = 0; i < 6; ++i)
    {
        is >> h.vertices[i].first >> h.vertices[i].second;
    }
    return is;
}
