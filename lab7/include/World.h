#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <iostream>
#include "Factory.h"
#include "NPC.h"
#include "Visitor.h"
class World {
private:
    std::vector<std::shared_ptr<NPC>> NPC_;
    int worldSize;

public:
    World(int size);
    void AddNPC(const std::string& type, const std::string& name, double x, double y, int damage, int health);
    void AllNPC() const;
    void Serialize(const std::string& filename) const;
    void Deserialize(const std::string& filename);
    void Engage(Visitor& visitor);
    void MoveNPC();
    void PrintMap() const;
};

#endif