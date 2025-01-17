#pragma once

#include "BaseRace.h"

class Terrans : public BaseRace
{
public:
	Terrans(float HP, float AP);
	virtual ~Terrans();

public:
	virtual void Attack(IRace& Target) override;
	virtual void Healing(int MinRange, int MaxRange) override;
	virtual void Defend() override;
	virtual void BoostDamage() override;
	
};

