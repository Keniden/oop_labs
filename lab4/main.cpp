// main.cpp
#include "Array.h"
#include "Hexagon.h"
#include "Pentagon.h"
#include "Octagon.h"
#include <iostream>
#include <memory>

int main() {
    Array<std::shared_ptr<Figure<int>>> figures;

    std::cout << "Введите координаты вершин пятиугольника (5 пар целых чисел):\n";
    Pentagon<int> pentagon;
    std::cin >> pentagon;

    figures.push_back(std::make_shared<Pentagon<int>>(pentagon));

    std::cout << "Введите координаты вершин шестиугольника (6 пар целых чисел):\n";
    Hexagon<int> hexagon;
    std::cin >> hexagon;

    figures.push_back(std::make_shared<Hexagon<int>>(hexagon));

    std::cout << "Введите координаты вершин восьмиугольника (8 пар целых чисел):\n";
    Octagon<int> octagon;
    std::cin >> octagon;

    figures.push_back(std::make_shared<Octagon<int>>(octagon));

    std::cout << "\nИнформация о фигурах:\n";
    for (const auto& fig : figures) {
        fig->Print();
        std::cout << "Площадь: " << fig->Area() << "\n";
        std::cout << "Центр: " << fig->Center() << "\n\n";
    }

    double total_area = 0.0;
    for (const auto& fig : figures) {
        total_area += static_cast<double>(*fig);
    }
    std::cout << "Общая площадь фигур: " << total_area << "\n";

    figures.removeAt(1);

    std::cout << "\nПосле удаления второй фигуры:\n";
    for (const auto& fig : figures) {
        fig->Print();
        std::cout << "Площадь: " << fig->Area() << "\n";
        std::cout << "Центр: " << fig->Center() << "\n\n";
    }

    Array<Hexagon<double>> hex_array;

    std::array<Point<double>, 6> hex_points = {
        Point<double>(1.0, 0.0),
        Point<double>(0.5, 0.8660254),
        Point<double>(-0.5, 0.8660254),
        Point<double>(-1.0, 0.0),
        Point<double>(-0.5, -0.8660254),
        Point<double>(0.5, -0.8660254)
    };

    Hexagon<double> hex_double(hex_points);
    hex_array.push_back(hex_double);

    std::cout << "\nHexagon<double> array:\n";
    for (const auto& hex : hex_array) {
        hex.Print();
        std::cout << "Площадь: " << hex.Area() << "\n";
        std::cout << "Центр: " << hex.Center() << "\n\n";
    }

    Array<Pentagon<float>> pent_array;

    std::array<Point<float>, 5> pent_points = {
        Point<float>(1.0f, 0.0f),
        Point<float>(0.309017f, 0.9510565f),
        Point<float>(-0.809017f, 0.5877852f),
        Point<float>(-0.809017f, -0.5877852f),
        Point<float>(0.309017f, -0.9510565f)
    };

    Pentagon<float> pent_float(pent_points);
    pent_array.push_back(pent_float);

    std::cout << "\nPentagon<float> array:\n";
    for (const auto& pent : pent_array) {
        pent.Print();
        std::cout << "Площадь: " << pent.Area() << "\n";
        std::cout << "Центр: " << pent.Center() << "\n\n";
    }

    return 0;
}
