#ifndef ELF_H
#define ELF_H

#include "NPC.h"


class Elf : public NPC {
  private:
    double distance = 10.0;
    double range = 50.0;

  public:
    using NPC::NPC;
    ~Elf() override;

  std::string GetType() const override;
  void KillOtherNPC(NPC& other) const override;
  void move(const position& NewCoords) override;
  bool CanMove(const position& NewCoords) const override;
};

#endif