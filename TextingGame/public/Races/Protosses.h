#pragma once

#include "BaseRace.h"

class Protosses : public BaseRace
{
public:
	Protosses(float HP, float AP);
	virtual ~Protosses();

public:
	virtual void Attack(IRace& Target) override;
	virtual void Healing(int MinRange, int MaxRange) override;
	virtual void Defend() override;
	virtual void BoostDamage() override;
};

