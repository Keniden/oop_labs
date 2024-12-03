// include/fight_manager.hpp
#ifndef FIGHT_MANAGER_HPP
#define FIGHT_MANAGER_HPP

#include "npc.hpp"
#include "visitor.hpp"
#include "concept.hpp"
#include <vector>
#include <memory>
#include <map>

class Location : public Subject {
    std::vector<std::shared_ptr<NPC>> npcs;
    std::map<std::string, std::shared_ptr<NPC>> nameMap;
public:
    bool addNPC(const std::shared_ptr<NPC>& npc);
    void listNPCs() const;
    bool saveToFile(const std::string& filename) const;
    bool loadFromFile(const std::string& filename);
    void battleMode(double range);
};


#endif 

