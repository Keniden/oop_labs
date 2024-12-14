#include "World.h"
#include "ObserverFile.h"
#include "ObserverConsole.h"
#include "Visitor.h"
#include <random>
#include <atomic>
#include <thread>
#include <mutex>
#include <shared_mutex>
#define WORLDSIZE 500


std::atomic<bool> Running { true };
std::shared_mutex npc_mutex;

int main() {
    World world(WORLDSIZE/10);
    Visitor visitor;
    ObserverConsole consoleObserver;
    ObserverFile fileObserver("log.txt");

    visitor.AddObserver(&consoleObserver);
    visitor.AddObserver(&fileObserver);

    double x, y, damage, health;

    const char* types[] = { "Bear", "Elf", "Robber" };
    for (int i = 0; i < 50; ++i) {
        damage = (rand() % 50) + 25;
        health = (rand() % 50) + 50;
        x = (rand() % WORLDSIZE);
        y = (rand() % WORLDSIZE);
        x /= 10;
        y /= 10;

        std::string type = types[i % 3];
        world.AddNPC(type, type + "_" + std::to_string(i), x, y, damage, health);
    }

    //world.Deserialize("dungeon.txt");
    std::cout << "Fighters in dungeon:\n";
    std::cout << "------------------------------------------------------------------" << std::endl;
    {
        std::shared_lock lock(npc_mutex);
        world.AllNPC();
    }
    std::cout << "------------------------------------------------------------------" << std::endl;

    std::thread movement_thread([&]() {
        while (Running) {
            {
                std::unique_lock lock(npc_mutex);
                world.MoveNPC();
            }
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    });

    std::thread battle_thread([&]() {
        while (Running) {
            {
                std::unique_lock lock(npc_mutex);
                world.Engage(visitor);
            }
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    });

    std::thread display_thread([&]() {
        while (Running) {
            {

                std::unique_lock lock(npc_mutex);
                world.PrintMap();
            }
            std::this_thread::sleep_for(std::chrono::seconds(3));
        }
        });

    std::this_thread::sleep_for(std::chrono::seconds(30));
    Running = false;

    movement_thread.join();
    battle_thread.join();
    display_thread.join();

    std::cout << "\nRemaining Fighters:\n";
    std::cout << "------------------------------------------------------------------" << std::endl;
    {
        std::shared_lock lock(npc_mutex);
        world.PrintMap();
        world.AllNPC();
    }
    std::cout << "------------------------------------------------------------------" << std::endl;
    return 0;
}
