#ifndef NPC_HPP
#define NPC_HPP

#include <string>
#include <memory>
#include "coords.hpp"

class BattleVisitor;

class NPC {
protected:
    std::string name;
    Coord position;
public:
    NPC(const std::string& name_, double x_, double y_) : name(name_), position(x_, y_) {}
    virtual ~NPC() = default;

    std::string getName() const { return name; }
    Coord getPosition() const { return position; }

    virtual std::string getType() const = 0;
    virtual void accept(BattleVisitor& visitor, NPC& other, bool& attackerDies, bool& defenderDies) = 0;

    virtual std::string serialize() const = 0;
    static std::shared_ptr<NPC> deserialize(const std::string& data);
};

class Bear : public NPC {
public:
    Bear(const std::string& name_, double x_, double y_) : NPC(name_, x_, y_) {}
    virtual std::string getType() const override { return "Bear"; }

    virtual void accept(BattleVisitor& visitor, NPC& other, bool& attackerDies, bool& defenderDies) override;
    
    virtual std::string serialize() const override {
        return "Bear," + name + "," + std::to_string(position.x) + "," + std::to_string(position.y);
    }
};

class Elf : public NPC {
public:
    Elf(const std::string& name_, double x_, double y_) : NPC(name_, x_, y_) {}
    virtual std::string getType() const override { return "Elf"; }

    virtual void accept(BattleVisitor& visitor, NPC& other, bool& attackerDies, bool& defenderDies) override;
    
    virtual std::string serialize() const override {
        return "Elf," + name + "," + std::to_string(position.x) + "," + std::to_string(position.y);
    }
};

class Bandit : public NPC {
public:
    Bandit(const std::string& name_, double x_, double y_) : NPC(name_, x_, y_) {}
    virtual std::string getType() const override { return "Bandit"; }

    virtual void accept(BattleVisitor& visitor, NPC& other, bool& attackerDies, bool& defenderDies) override;
    
    virtual std::string serialize() const override {
        return "Bandit," + name + "," + std::to_string(position.x) + "," + std::to_string(position.y);
    }
};

class NPCFactory {
public:
    static std::shared_ptr<NPC> createNPC(const std::string& type, const std::string& name, double x, double y);
    static std::shared_ptr<NPC> createNPCFromString(const std::string& data);
};

#endif
