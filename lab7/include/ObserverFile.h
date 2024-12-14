#ifndef OBSERVERFILE_H
#define OBSERVERFILE_H

#include "Observer.h"

class ObserverFile : public Observer {
private:
    std::ofstream logFile;

public:
    ObserverFile(const std::string& filename);
    void Event(const std::string& event) override;
    ~ObserverFile();
};

#endif