#include "npc.hpp"
#include "fight_manager.hpp"
#include <sstream>

void Bear::accept(BattleVisitor& visitor, NPC& other, bool& attackerDies, bool& defenderDies) {
    visitor.visit(*this, other, attackerDies, defenderDies);
}

void Elf::accept(BattleVisitor& visitor, NPC& other, bool& attackerDies, bool& defenderDies) {
    visitor.visit(*this, other, attackerDies, defenderDies);
}

void Bandit::accept(BattleVisitor& visitor, NPC& other, bool& attackerDies, bool& defenderDies) {
    visitor.visit(*this, other, attackerDies, defenderDies);
}

std::shared_ptr<NPC> NPCFactory::createNPC(const std::string& type, const std::string& name, double x, double y) {
    if(type == "Bear") return std::make_shared<Bear>(name, x, y);
    if(type == "Elf") return std::make_shared<Elf>(name, x, y);
    if(type == "Bandit") return std::make_shared<Bandit>(name, x, y);
    return nullptr;
}

std::shared_ptr<NPC> NPC::deserialize(const std::string& data) {
    return NPCFactory::createNPCFromString(data);
}

std::shared_ptr<NPC> NPCFactory::createNPCFromString(const std::string& data) {
    std::stringstream ss(data);
    std::string type, name, xStr, yStr;
    if(!std::getline(ss, type, ',')) return nullptr;
    if(!std::getline(ss, name, ',')) return nullptr;
    if(!std::getline(ss, xStr, ',')) return nullptr;
    if(!std::getline(ss, yStr, ',')) return nullptr;
    double x = std::stod(xStr);
    double y = std::stod(yStr);
    return createNPC(type, name, x, y);
}
