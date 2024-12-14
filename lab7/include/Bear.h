#ifndef BEAR_H
#define BEAR_H

#include "NPC.h"

class Bear : public NPC
{
private:
	double distance = 5.0;
	double range = 10.0;

public:
	using NPC::NPC;
	~Bear() override;

	std::string GetType() const override;
	void KillOtherNPC(NPC &other) const override;
	void move(const position &NewCoords) override;
	bool CanMove(const position &NewCoords) const override;
};

#endif
