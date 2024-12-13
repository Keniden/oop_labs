#ifndef NPC_HPP
#define NPC_HPP

#include <string>
#include <memory>
#include "coords.hpp"


struct NPC {
    std::string type;
    std::string name;
    double x;
    double y;
    bool alive;
    double moveRange;
    double killRange;
};

#endif
