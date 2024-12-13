#ifndef COORDS_HPP
#define COORDS_HPP

#include <cmath>

class Coord {
public:
    double x;
    double y;

    Coord(double x_=0.0, double y_=0.0) : x(x_), y(y_) {}

    double distanceTo(const Coord& other) const {
        double dx = x - other.x;
        double dy = y - other.y;
        return std::sqrt(dx*dx + dy*dy);
    }
};

#endif
