#include "../include/Pentagon.h"
#include <cmath>
#include <typeinfo>
#include <iostream>
#include <utility>

Pentagon::Pentagon()
{
    for (int i = 0; i < 5; ++i)
    {
        vertices[i] = {0.0, 0.0};
    }
}

Pentagon::Pentagon(const std::pair<double, double> verts[5])
{
    for (int i = 0; i < 5; ++i)
    {
        vertices[i] = verts[i];
    }
    if (!isRegular())
    {
        std::cerr << "cоздан неправильный пятиугольник.\n";
    }
}

Pentagon::Pentagon(const Pentagon &other)
{
    for (int i = 0; i < 5; ++i)
    {
        vertices[i] = other.vertices[i];
    }
}

Pentagon::Pentagon(Pentagon &&other) noexcept
{
    for (int i = 0; i < 5; ++i)
    {
        vertices[i] = std::move(other.vertices[i]);
    }
}

Pentagon::~Pentagon() {}

Pentagon &Pentagon::operator=(const Pentagon &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 5; ++i)
        {
            vertices[i] = other.vertices[i];
        }
    }
    return *this;
}

Pentagon &Pentagon::operator=(Pentagon &&other) noexcept
{
    if (this != &other)
    {
        for (int i = 0; i < 5; ++i)
        {
            vertices[i] = std::move(other.vertices[i]);
        }
    }
    return *this;
}

Figure &Pentagon::operator=(const Figure &other)
{
    if (this != &other)
    {
        if (typeid(*this) == typeid(other))
        {
            const Pentagon &pentagon = dynamic_cast<const Pentagon &>(other);
            *this = pentagon;
        }
        else
        {
            std::cerr << "типы не совпадают.\n";
        }
    }
    return *this;
}

bool Pentagon::operator==(const Pentagon &other) const
{
    for (int i = 0; i < 5; ++i)
    {
        if (vertices[i] != other.vertices[i])
        {
            return false;
        }
    }
    return true;
}

bool Pentagon::operator==(const Figure &other) const
{
    if (typeid(*this) != typeid(other))
    {
        return false;
    }
    const Pentagon &pentagon = dynamic_cast<const Pentagon &>(other);
    return *this == pentagon;
}

bool Pentagon::isRegular(double epsilon) const
{
    double side_length = 0.0;
    for (int i = 0; i < 5; ++i)
    {
        int j = (i + 1) % 5;
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

void Pentagon::Print() const
{
    std::cout << "вершины:\n";
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "(" << vertices[i].first << ", " << vertices[i].second << ")\n";
    }
}

double Pentagon::Area() const
{
    double area = 0.0;
    for (int i = 0; i < 5; ++i)
    {
        const auto &[x1, y1] = vertices[i];
        const auto &[x2, y2] = vertices[(i + 1) % 5];
        area += (x1 * y2 - x2 * y1);
    }
    return std::abs(area) / 2.0;
}

std::pair<double, double> Pentagon::Center() const
{
    double x_sum = 0.0;
    double y_sum = 0.0;
    for (int i = 0; i < 5; ++i)
    {
        x_sum += vertices[i].first;
        y_sum += vertices[i].second;
    }
    return {x_sum / 5, y_sum / 5};
}

Pentagon::operator double() const
{
    return this->Area();
}

Figure *Pentagon::Clone() const
{
    return new Pentagon(*this);
}

std::ostream &operator<<(std::ostream &os, const Pentagon &p)
{
    for (int i = 0; i < 5; ++i)
    {
        os << p.vertices[i].first << " " << p.vertices[i].second << " ";
    }
    return os;
}

std::istream &operator>>(std::istream &is, Pentagon &p)
{
    for (int i = 0; i < 5; ++i)
    {
        is >> p.vertices[i].first >> p.vertices[i].second;
    }
    return is;
}
