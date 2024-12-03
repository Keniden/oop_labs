// include/concept.hpp
#ifndef CONCEPT_HPP
#define CONCEPT_HPP

#include <string>
#include <vector>
#include <memory>

class BattleVisitor;

class Observer {
public:
    virtual void onKill(const std::string& killer, const std::string& victim) = 0;
    virtual ~Observer() = default;
};

class Subject {
    std::vector<std::shared_ptr<Observer>> observers;
public:
    void attach(const std::shared_ptr<Observer>& observer) {
        observers.emplace_back(observer);
    }

protected:
    void notify(const std::string& killer, const std::string& victim) {
        for(auto& obs : observers) {
            obs->onKill(killer, victim);
        }
    }

    friend class BattleVisitor;
};

#endif
