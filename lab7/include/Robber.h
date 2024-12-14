#ifndef ROBBER_H
#define ROBBER_H

#include "NPC.h"


class Robber : public NPC {
  private:
    double distance = 10.0;
    double range = 10.0;

  public:
    using NPC::NPC;
    ~Robber() override;

    std::string GetType() const override;
    void KillOtherNPC(NPC& other) const override;
    void move(const position& NewCoords) override;
    bool CanMove(const position& NewCoords) const override;
};

#endif