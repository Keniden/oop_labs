#include "fight_manager.hpp"
#include <algorithm>
#include <iostream>
#include <random>
#include <atomic>
#include <chrono>
#include <thread>
#include <mutex>
#include <cmath>
#include <condition_variable>
#include <queue>

Location location;
std::atomic<bool> stopGame(false);

template<typename T>
class SafeQueue {
    std::queue<T> q; 
    std::mutex m;
    std::condition_variable cv;
public:
    void push(const T& val) {
        {
            std::lock_guard<std::mutex> lg(m);
            q.push(val);
        }
        cv.notify_one();
    }

    T pop() {
        std::unique_lock<std::mutex> lock(m);
        cv.wait(lock, [&]{ return !q.empty(); });
        T val = q.front();
        q.pop();
        return val;
    }

    bool empty() {
        std::lock_guard<std::mutex> lg(m);
        return q.empty();
    }
};

SafeQueue<std::pair<int,int>> battleQueue;

bool Location::addNPC(const NPC& npc) {
    std::unique_lock<std::shared_mutex> lock(npcsMutex);
    if(npc.x < 0 || npc.x > 100 || npc.y < 0 || npc.y > 100) {
        std::cout << "Координаты вне диапазона." << std::endl;
        return false;
    }
    for (auto &n : npcs) {
        if(n.name == npc.name && n.alive) {
            std::cout << "Имя NPC должно быть уникальным." << std::endl;
            return false;
        }
    }
    npcs.push_back(npc);
    return true;
}

void Location::printMap() const {
    static std::mutex coutMutex;
    std::shared_lock<std::shared_mutex> lock(npcsMutex);
    std::lock_guard<std::mutex> lg(coutMutex);
    std::cout << "----- MAP -----" << std::endl;
    for (auto &n : npcs) {
        if(n.alive) {
            std::cout << n.type << "(" << n.name << "): [" << n.x << "," << n.y << "]" << std::endl;
        }
    }
    std::cout << "--------------" << std::endl;
}

void Location::listSurvivors() const {
    std::shared_lock<std::shared_mutex> lock(npcsMutex);
    std::cout << "Survivors:" << std::endl;
    for (auto &n : npcs) {
        if(n.alive) {
            std::cout << n.type << " " << n.name << std::endl;
        }
    }
}

void Location::moveAll(std::function<void(NPC&)> func) {
    std::unique_lock<std::shared_mutex> lock(npcsMutex);
    for (auto &n : npcs) {
        if(n.alive) {
            func(n);
        }
    }
}

std::vector<NPC> Location::getNPCsSnapshot() const {
    std::shared_lock<std::shared_mutex> lock(npcsMutex);
    return npcs;
}

void Location::killNPC(const std::string& victimName, const std::string& killerName) {
    std::unique_lock<std::shared_mutex> lock(npcsMutex);
    for (auto &n : npcs) {
        if(n.name == victimName && n.alive) {
            n.alive = false;
            notify(killerName, victimName);
            return;
        }
    }
}

bool Location::getTwoNPCsForFight(int i, int j, NPC& ni, NPC& nj) {
    std::shared_lock<std::shared_mutex> lock(npcsMutex);
    if(i<0 || i>=(int)npcs.size() || j<0 || j>=(int)npcs.size()) return false;
    if(!npcs[i].alive || !npcs[j].alive) return false;
    ni = npcs[i];
    nj = npcs[j];
    return true;
}

// Инициализация 50 NPC
void initNPCs() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(0,100);
    std::vector<std::string> types = {"Elf","Bear","Bandit"};
    for (int i = 0; i < 50; ++i) {
        NPC npc;
        npc.type = types[std::uniform_int_distribution<>(0,2)(gen)];
        npc.name = "NPC_" + std::to_string(i);
        npc.x = dist(gen);
        npc.y = dist(gen);
        npc.alive = true;
        if (npc.type == "Elf") { npc.moveRange = 10.0; npc.killRange = 50.0; }
        else if (npc.type == "Bear") { npc.moveRange = 5.0; npc.killRange = 10.0; }
        else { npc.moveRange = 10.0; npc.killRange = 10.0; }

        location.addNPC(npc);
    }
}

// Поток перемещения NPC
void moveNPCsThread() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> moveDist(-1.0,1.0);

    while(!stopGame) {
        // Двигаем NPC
        location.moveAll([&](NPC& n){
            double dx = moveDist(gen)*n.moveRange;
            double dy = moveDist(gen)*n.moveRange;
            n.x = std::max(0.0,std::min(100.0,n.x+dx));
            n.y = std::max(0.0,std::min(100.0,n.y+dy));
        });

        // Проверяем на бои
        auto snapshot = location.getNPCsSnapshot();
        for (size_t i=0; i<snapshot.size(); ++i) {
            for (size_t j=i+1; j<snapshot.size(); ++j) {
                if(!snapshot[i].alive || !snapshot[j].alive) continue;
                double dx = snapshot[i].x - snapshot[j].x;
                double dy = snapshot[i].y - snapshot[j].y;
                double dist = std::sqrt(dx*dx+dy*dy);
                if(dist <= snapshot[i].killRange || dist <= snapshot[j].killRange) {
                    battleQueue.push({(int)i,(int)j});
                }
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}


void battleThread() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dice(1,6);

    while(!stopGame) {
        auto task = battleQueue.pop();
        int i = task.first;
        int j = task.second;
        if(i<0 || j<0) continue;

        NPC ni, nj;
        if(!location.getTwoNPCsForFight(i,j,ni,nj)) {
            continue;
        }

        int attack = dice(gen);
        int defense = dice(gen);

        
        if(attack > defense) {
            location.killNPC(nj.name, ni.name);
        } else if(defense > attack) {
            location.killNPC(ni.name, nj.name);
        }
        
    }
}
