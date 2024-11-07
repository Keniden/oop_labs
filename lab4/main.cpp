#include "Array.h"
#include "Pentagon.h"
#include "Hexagon.h"
#include "Octagon.h"
#include <iostream>
#include <memory>
#include <cmath>

int main() {
    Array<std::shared_ptr<Figure<int>>> figures;

    std::cout << "Enter the coordinates of the pentagon vertices (5 pairs of integers):\n";
    Pentagon<int> pentagon;
    std::cin >> pentagon;

    figures.push_back(std::make_shared<Pentagon<int>>(pentagon));

    std::cout << "Enter the coordinates of the hexagon vertices (6 pairs of integers):\n";
    Hexagon<int> hexagon;
    std::cin >> hexagon;

    figures.push_back(std::make_shared<Hexagon<int>>(hexagon));

    std::cout << "Enter the coordinates of the octagon vertices (8 pairs of integers):\n";
    Octagon<int> octagon;
    std::cin >> octagon;

    figures.push_back(std::make_shared<Octagon<int>>(octagon));

    std::cout << "\nFigure information:\n";
    for (const auto& fig : figures) {
        fig->Print();
        std::cout << "Area: " << fig->Area() << "\n";
        std::cout << "Center: " << fig->Center() << "\n\n";
    }

    double total_area = 0.0;
    for (const auto& fig : figures) {
        total_area += static_cast<double>(*fig);
    }
    std::cout << "Total area of figures: " << total_area << "\n";

    figures.removeAt(1);

    std::cout << "\nAfter removing the second figure:\n";
    for (const auto& fig : figures) {
        fig->Print();
        std::cout << "Area: " << fig->Area() << "\n";
        std::cout << "Center: " << fig->Center() << "\n\n";
    }

    Array<Hexagon<double>> hex_array;

    std::array<Point<double>, 6> hex_points = {
        Point<double>(0.0, 0.0),
        Point<double>(1.0, 0.0),
        Point<double>(1.5, std::sqrt(3)/2),
        Point<double>(1.0, std::sqrt(3)),
        Point<double>(0.0, std::sqrt(3)),
        Point<double>(-0.5, std::sqrt(3)/2)
    };

    Hexagon<double> hex_double(hex_points);
    hex_array.push_back(hex_double);

    std::cout << "\nHexagon<double> array:\n";
    for (const auto& hex : hex_array) {
        hex.Print();
        std::cout << "Area: " << hex.Area() << "\n";
        std::cout << "Center: " << hex.Center() << "\n\n";
    }

    Array<Pentagon<float>> pent_array;

    std::array<Point<float>, 5> pent_points = {
        Point<float>(0.0f, 0.0f),
        Point<float>(1.0f, 0.0f),
        Point<float>(1.5f, 1.0f),
        Point<float>(0.5f, 1.5f),
        Point<float>(-0.5f, 1.0f)
    };

    Pentagon<float> pent_float(pent_points);
    pent_array.push_back(pent_float);

    std::cout << "\nPentagon<float> array:\n";
    for (const auto& pent : pent_array) {
        pent.Print();
        std::cout << "Area: " << pent.Area() << "\n";
        std::cout << "Center: " << pent.Center() << "\n\n";
    }

    return 0;
}
