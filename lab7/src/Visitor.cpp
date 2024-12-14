#include "Visitor.h"

void Visitor::AddObserver(Observer* observer) {
    observers.push_back(observer);
}

void Visitor::Engage(std::vector<std::shared_ptr<NPC>>& NPC) {
    for (size_t i = 0; i < NPC.size(); ++i) {
        for (size_t j = i + 1; j < NPC.size(); ++j) {
            auto firstNPS = NPC[i];
            auto secondNPS = NPC[j];

            if (!firstNPS->Alive() || !secondNPS->Alive()) {
                continue;
            }

            firstNPS->KillOtherNPC(*secondNPS);
            secondNPS->KillOtherNPC(*firstNPS);

            if (!firstNPS->Alive() && !secondNPS->Alive()) {
                Announce(firstNPS->Name() + " and " + secondNPS->Name() + " beats each other");
            } else if (!firstNPS->Alive()) {
                Announce(secondNPS->Name() + " beats " + firstNPS->Name());
            }
            else if (!secondNPS->Alive()) {
                Announce(firstNPS->Name() + " beats " + secondNPS->Name());
            }
        }
    }
}
