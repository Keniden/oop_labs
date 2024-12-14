#include "Factory.h"
#include "Bear.h"
#include "Elf.h"
#include "Robber.h"

std::shared_ptr<NPC> Factory::CreateNPC(const std::string& type, const std::string& name, double x, double y, int damage, int health) {
    if (type == "Bear") {
        return std::make_shared<Bear>(name, x, y, damage, health);
    }
    if (type == "Elf") {
        return std::make_shared<Elf>(name, x, y, damage, health);
    }
    if (type == "Robber") {
        return std::make_shared<Robber>(name, x, y, damage, health);
    }
    return nullptr;
}
