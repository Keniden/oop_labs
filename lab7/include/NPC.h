#ifndef NPC_H
#define NPC_H

#include <string>

struct position {
    double x;
    double y;
};

class NPC {
  protected:
    position pos;
    std::string name;
    bool alive = true;
    int damage;
    int health;

  public:
    NPC(std::string name, double x, double y, int damage, int health);
    std::string Name() const noexcept;
    bool Alive() const noexcept;
    position GetPos() const noexcept;
    void KillThisNPC();
    void ChangeHealth(int otherDamage);
    int GetDamage() const noexcept;
    int GetHealth() const noexcept;


    virtual std::string GetType() const = 0;
    virtual void move(const position& NewCoords) = 0;
    virtual bool CanMove(const position& NewCoords) const = 0;
    virtual void KillOtherNPC(NPC& other) const = 0;
    virtual ~NPC() = default;
};
#endif
