// include/observer.hpp
#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include "concept.hpp"
#include <fstream>
#include <iostream>

class ConsoleObserver : public Observer {
public:
    virtual void onKill(const std::string& killer, const std::string& victim) override {
        std::cout << killer << " killed " << victim << std::endl;
    }
};

class FileObserver : public Observer {
    std::ofstream file;
public:
    FileObserver(const std::string& filename) {
        file.open(filename, std::ios::app);
        if(!file.is_open()) {
            std::cerr << "Не удалось открыть файл " << filename << " для записи." << std::endl;
        }
    }

    virtual void onKill(const std::string& killer, const std::string& victim) override {
        if(file.is_open()) {
            file << killer << " killed " << victim << std::endl;
        }
    }

    ~FileObserver() {
        if(file.is_open()) file.close();
    }
};

#endif
