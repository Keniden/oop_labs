#ifndef OBSERVERCONSOLE_H
#define OBSERVERCONSOLE_H

#include "Observer.h"
#include <iostream>

class ObserverConsole : public Observer {
public:
    void Event(const std::string& event) override;
};

#endif