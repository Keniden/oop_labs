#ifndef VISITOR_H
#define VISITOR_H

#include <vector>
#include "NPC.h"
#include "Observer.h"
#include "ObserverConsole.h"
#include "ObserverFile.h"
#include <memory>

class Visitor {
private:
    void Announce(const std::string& event) {
        for (auto observer : observers) {
            observer->Event(event);
        }
    }
    std::vector<Observer*> observers;

public:
    void AddObserver(Observer* observer);
    void Engage(std::vector<std::shared_ptr<NPC>>& NPC);
};

#endif