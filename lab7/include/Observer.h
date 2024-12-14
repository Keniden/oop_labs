#ifndef OBSERVER_H
#define OBSERVER_H

#include <fstream>
#include <string>

class Observer {
public:
    virtual void Event(const std::string& event) = 0;
    virtual ~Observer() = default;
};

#endif