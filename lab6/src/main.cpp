// src/main.cpp
#include <iostream>
#include <memory>
#include "npc.hpp"
#include "observer.hpp"
#include "fight_manager.hpp"

int main() {
    Location location;

    auto consoleObs = std::make_shared<ConsoleObserver>();
    auto fileObs = std::make_shared<FileObserver>("log.txt");
    location.attach(consoleObs);
    location.attach(fileObs);

    while(true) {
        std::cout << "\nМеню:\n"
                  << "1. Добавить NPC\n"
                  << "2. Сохранить в файл\n"
                  << "3. Загрузить из файла\n"
                  << "4. Показать NPC\n"
                  << "5. Боевой режим\n"
                  << "6. Выход\n"
                  << "Выберите действие: ";
        int choice;
        std::cin >> choice;
        if(choice == 1) {
            std::string type, name;
            double x, y;
            std::cout << "Введите тип NPC (Bear, Elf, Bandit): ";
            std::cin >> type;
            std::cout << "Введите уникальное имя: ";
            std::cin >> name;
            std::cout << "Введите координату X (0-500): ";
            std::cin >> x;
            std::cout << "Введите координату Y (0-500): ";
            std::cin >> y;
            auto npc = NPCFactory::createNPC(type, name, x, y);
            if(npc) {
                if(location.addNPC(npc)) {
                    std::cout << "NPC добавлен." << std::endl;
                }
            }
            else {
                std::cout << "Неверный тип NPC." << std::endl;
            }
        }
        else if(choice == 2) {
            std::string filename;
            std::cout << "Введите имя файла для сохранения: ";
            std::cin >> filename;
            if(location.saveToFile(filename)) {
                std::cout << "Сохранено успешно." << std::endl;
            }
            else {
                std::cout << "Ошибка сохранения." << std::endl;
            }
        }
        else if(choice == 3) {
            std::string filename;
            std::cout << "Введите имя файла для загрузки: ";
            std::cin >> filename;
            if(location.loadFromFile(filename)) {
                std::cout << "Загружено успешно." << std::endl;
            }
            else {
                std::cout << "Ошибка загрузки." << std::endl;
            }
        }
        else if(choice == 4) {
            location.listNPCs();
        }
        else if(choice == 5) {
            double range;
            std::cout << "Введите дальность боя: ";
            std::cin >> range;
            location.battleMode(range);
            std::cout << "Боевой режим завершен." << std::endl;
        }
        else if(choice == 6) {
            break;
        }
        else {
            std::cout << "Неверный выбор." << std::endl;
        }
    }

    return 0;
}
