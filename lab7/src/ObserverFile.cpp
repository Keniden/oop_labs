#include "ObserverFile.h"

ObserverFile::ObserverFile(const std::string& filename) : logFile(filename) {}

void ObserverFile::Event(const std::string& event) {
    this->logFile << event << std::endl;
}

ObserverFile::~ObserverFile() {
    if (logFile.is_open()) {
        logFile.close();
    }
}
