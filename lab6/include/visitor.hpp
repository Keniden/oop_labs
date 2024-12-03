#ifndef VISITOR_HPP
#define VISITOR_HPP

#include "concept.hpp"

class NPC;

class BattleVisitor {
    double range;
    Subject& subject;
public:
    BattleVisitor(double range_, Subject& subject_) : range(range_), subject(subject_) {}
    void visit(NPC& attacker, NPC& defender, bool& attackerDies, bool& defenderDies);
};

#endif
