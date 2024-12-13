#ifndef FIGHT_MANAGER_HPP
#define FIGHT_MANAGER_HPP

#include "npc.hpp"
#include "observer.hpp"
#include <vector>
#include <shared_mutex>
#include <functional>
#include <atomic> 

class Location : public Subject {
    std::vector<NPC> npcs;
    mutable std::shared_mutex npcsMutex;
public:
    bool addNPC(const NPC& npc);
    void printMap() const;
    void listSurvivors() const;
    void moveAll(std::function<void(NPC&)> func);
    std::vector<NPC> getNPCsSnapshot() const;
    void killNPC(const std::string& victimName, const std::string& killerName);

    bool getTwoNPCsForFight(int i, int j, NPC& ni, NPC& nj);
};

extern Location location;
extern std::atomic<bool> stopGame; 

void initNPCs();
void moveNPCsThread();
void battleThread();

#endif
