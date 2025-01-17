#pragma once

#include "BaseRace.h"

class Zergs : public BaseRace
{
public:
	Zergs(float HP, float AP);
	virtual ~Zergs();

public:
	virtual void Attack(IRace& Target) override;
	virtual void Healing(int MinRange, int MaxRange) override;
	virtual void Defend() override;
	virtual void BoostDamage() override;
};

