#include "NPC.h"
#include <stdexcept>

NPC::NPC(std::string name, double x, double y, int damage, int health)
{
  this->name = name;
  this->pos = {x, y};
  this->damage = damage;
  this->health = health;
}

std::string NPC::Name() const noexcept
{
  return this->name;
}

bool NPC::Alive() const noexcept
{
  return this->alive;
}

position NPC::GetPos() const noexcept
{
  return this->pos;
}

void NPC::KillThisNPC()
{
  this->alive = false;
  this->health = 0;
}

int NPC::GetDamage() const noexcept
{
  return this->damage;
}

int NPC::GetHealth() const noexcept
{
  return this->health;
}

void NPC::ChangeHealth(int otherDamage)
{
  this->health = this->health - otherDamage;
}
