#include "Robber.h"
#include <math.h>

Robber::~Robber() = default;

std::string Robber::GetType() const {
  return "Robber";
}

void Robber::KillOtherNPC(NPC& other) const {
  position othPos = other.GetPos();
  position thPos = this->GetPos();
  double length = 0;
  length = sqrt(pow(othPos.x - thPos.x , 2) + pow(othPos.y - thPos.y, 2));

  if (this->range >= length && other.GetType() == "Robber") {
    if (this->damage >= other.GetHealth()) {
      other.KillThisNPC();
    } else {
      other.ChangeHealth(this->damage);
    }
  }
}

void Robber::move(const position& NewCoords) {
  if (CanMove(NewCoords)) {
    this->pos = NewCoords;
  }
}


bool Robber::CanMove(const position& NewCoords) const {
  position thPos = this->GetPos();
  double length = 0;
  length = sqrt(pow(NewCoords.x - thPos.x , 2) + pow(NewCoords.y - thPos.y, 2));
  if (length <= distance) return true;
  return false;
}