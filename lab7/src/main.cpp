#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include "npc.hpp"
#include "observer.hpp"
#include "fight_manager.hpp"

int main() {
    auto consoleObs = std::make_shared<ConsoleObserver>();
    auto fileObs = std::make_shared<FileObserver>("log.txt");
    location.attach(consoleObs);
    location.attach(fileObs);

    initNPCs();

    std::thread mover(moveNPCsThread);
    std::thread fighter(battleThread);

    auto start = std::chrono::steady_clock::now();

    while(true) {
        location.printMap();
        std::this_thread::sleep_for(std::chrono::seconds(1));
        auto now = std::chrono::steady_clock::now();
        auto dur = std::chrono::duration_cast<std::chrono::seconds>(now - start).count();
        if(dur >= 30) {
            stopGame = true;
            break;
        }
    }
    mover.join();
    fighter.join();

    location.listSurvivors();

    return 0;
}
