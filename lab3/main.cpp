#include <iostream>
#include "./src/FigureArray.cpp"
#include "./src/Pentagon.cpp"
#include "./src/Hexagon.cpp"
#include "./src/Octagon.cpp"

int main()
{
    FigureArray figures;
    int choice;
    while (true)
    {
        std::cout << "Меню:\n";
        std::cout << "1. Добавить фигуру\n";
        std::cout << "2. Удалить фигуру\n";
        std::cout << "3. Показать фигуры\n";
        std::cout << "4. Вычислить общую площадь\n";
        std::cout << "5. Выйти\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        if (choice == 1)
        {
            std::cout << "Выберите фигуру для добавления:\n";
            std::cout << "1. Пятиугольник\n";
            std::cout << "2. Шестиугольник\n";
            std::cout << "3. Восьмиугольник\n";
            int fig_choice;
            std::cin >> fig_choice;
            if (fig_choice == 1)
            {
                auto pentagon = new Pentagon();
                std::cout << "Введите координаты 5 вершин:\n";
                std::cin >> *pentagon;
                figures.push_back(pentagon);
            }
            else if (fig_choice == 2)
            {
                auto hexagon = new Hexagon();
                std::cout << "Введите координаты 6 вершин:\n";
                std::cin >> *hexagon;
                figures.push_back(hexagon);
            }
            else if (fig_choice == 3)
            {
                auto octagon = new Octagon();
                std::cout << "Введите координаты 8 вершин:\n";
                std::cin >> *octagon;
                figures.push_back(octagon);
            }
            else
            {
                std::cout << "Неверный выбор фигуры.\n";
            }
        }
        else if (choice == 2)
        {
            std::cout << "Введите индекс фигуры для удаления: ";
            size_t index;
            std::cin >> index;
            figures.removeAt(index);
        }
        else if (choice == 3)
        {
            figures.printAll();
        }
        else if (choice == 4)
        {
            double total_area = figures.totalArea();
            std::cout << "Общая площадь: " << total_area << "\n";
        }
        else if (choice == 5)
        {
            break;
        }
        else
        {
            std::cout << "Неверный выбор.\n";
        }
    }
    return 0;
}
