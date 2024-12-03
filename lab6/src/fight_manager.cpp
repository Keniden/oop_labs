#include "fight_manager.hpp"
#include "visitor.hpp" 
#include <cmath>
#include <algorithm>
#include <fstream>
#include <iostream>

void BattleVisitor::visit(NPC& attacker, NPC& defender, bool& attackerDies, bool& defenderDies) {
    double distance = attacker.getPosition().distanceTo(defender.getPosition());
    if(distance > range) return;

    std::string attackerType = attacker.getType();
    std::string defenderType = defender.getType();

    bool attackerKills = false;
    bool defenderKills = false;

    if(attackerType == "Elf") {
        if(defenderType == "Bandit") attackerKills = true;
    }
    else if(attackerType == "Bandit") {
        if(defenderType == "Bandit") attackerKills = true;
    }
    else if(attackerType == "Bear") {
        if(defenderType == "Elf") attackerKills = true;
    }

    //защитник атакует нападающего
    if(defenderType == "Elf") {
        if(attackerType == "Bandit") defenderKills = true;
    }
    else if(defenderType == "Bandit") {
        if(attackerType == "Bandit") defenderKills = true;
    }
    else if(defenderType == "Bear") {
        if(attackerType == "Elf") defenderKills = true;
    }

    if(attackerKills && defenderKills) {
        attackerDies = true;
        defenderDies = true;
        subject.notify(attacker.getName(), defender.getName());
    }
    else if(attackerKills) {
        defenderDies = true;
        subject.notify(attacker.getName(), defender.getName());
    }
    else if(defenderKills) {
        attackerDies = true;
        subject.notify(defender.getName(), attacker.getName());
    }
}


bool Location::addNPC(const std::shared_ptr<NPC>& npc) {
    if(npc->getPosition().x < 0 || npc->getPosition().x > 500 ||
       npc->getPosition().y < 0 || npc->getPosition().y > 500) {
        std::cout << "Координаты вне допустимого диапазона (0-500)." << std::endl;
        return false;
    }
    if(nameMap.find(npc->getName()) != nameMap.end()) {
        std::cout << "Имя NPC должно быть уникальным." << std::endl;
        return false;
    }
    npcs.emplace_back(npc);
    nameMap[npc->getName()] = npc;
    return true;
}

void Location::listNPCs() const {
    std::cout << "Список NPC в локации:" << std::endl;
    for(const auto& npc : npcs) {
        std::cout << npc->getType() << " - " << npc->getName()
                  << " (" << npc->getPosition().x << ", " << npc->getPosition().y << ")" << std::endl;
    }
}

bool Location::saveToFile(const std::string& filename) const {
    std::ofstream ofs(filename);
    if(!ofs.is_open()) return false;
    for(const auto& npc : npcs) {
        ofs << npc->serialize() << std::endl;
    }
    ofs.close();
    return true;
}

bool Location::loadFromFile(const std::string& filename) {
    std::ifstream ifs(filename);
    if(!ifs.is_open()) return false;
    npcs.clear();
    nameMap.clear();
    std::string line;
    while(std::getline(ifs, line)) {
        auto npc = NPC::deserialize(line);
        if(npc) {
            npcs.emplace_back(npc);
            nameMap[npc->getName()] = npc;
        }
    }
    ifs.close();
    return true;
}

void Location::battleMode(double range) {
    BattleVisitor visitor(range, *this);
    std::vector<std::shared_ptr<NPC>> originalNPCs = npcs;
    std::vector<std::pair<std::shared_ptr<NPC>, std::shared_ptr<NPC>>> battles;

    for(size_t i = 0; i < originalNPCs.size(); ++i) {
        for(size_t j = i + 1; j < originalNPCs.size(); ++j) {
            battles.emplace_back(std::make_pair(originalNPCs[i], originalNPCs[j]));
        }
    }

    std::map<std::string, bool> deaths;

    for(auto& pair : battles) {
        auto attacker = pair.first;
        auto defender = pair.second;
        if(deaths[attacker->getName()] || deaths[defender->getName()]) continue;

        bool attackerDies = false, defenderDies = false;
        attacker->accept(visitor, *defender, attackerDies, defenderDies);

        if(attackerDies) deaths[attacker->getName()] = true;
        if(defenderDies) deaths[defender->getName()] = true;
    }

    npcs.erase(std::remove_if(npcs.begin(), npcs.end(),
        [&](const std::shared_ptr<NPC>& npc) -> bool {
            return deaths[npc->getName()];
        }), npcs.end());

    nameMap.clear();
    for(const auto& npc : npcs) {
        nameMap[npc->getName()] = npc;
    }
}
