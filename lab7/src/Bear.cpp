#include "Bear.h"
#include <math.h>

Bear::~Bear() = default;

std::string Bear::GetType() const
{
	return "Bear";
}

void Bear::KillOtherNPC(NPC &other) const
{
	position othPos = other.GetPos();
	position thPos = this->GetPos();
	double length = 0;
	length = sqrt(pow(othPos.x - thPos.x, 2) + pow(othPos.y - thPos.y, 2));

	if (this->range >= length && other.GetType() == "Elf")
	{
		if (this->damage >= other.GetHealth())
		{
			other.KillThisNPC();
		}
		else
		{
			other.ChangeHealth(this->damage);
		}
	}
}

void Bear::move(const position &NewCoords)
{
	if (CanMove(NewCoords))
	{
		this->pos = NewCoords;
	}
}

bool Bear::CanMove(const position &NewCoords) const
{
	position thPos = this->GetPos();
	double length = 0;
	length = sqrt(pow(NewCoords.x - thPos.x, 2) + pow(NewCoords.y - thPos.y, 2));
	if (length <= distance)
		return true;
	return false;
}
