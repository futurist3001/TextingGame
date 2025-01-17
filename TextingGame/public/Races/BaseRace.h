#pragma once

#include "RaceInterface.h"

class BaseRace : public IRace
{
protected:
	float DefaultHealth;
	float CurrentHealth;

	float DefaultDamage;
	float Damage; // attack enemy with this damage

	float Armour; // children will assign value

	float DefendCoefficient; // decrease Damage of enemies (children will assign value)
	float BoostDamageCoeficient; // increase own damage (children will assign value)

private:
	float Damaged—oefficient; // for proper logic to get corret damage

public:
	BaseRace(float HP = 100.f, float AP = 50.f);
	BaseRace();
	virtual ~BaseRace();

	const float GetCurrentHealth() const { return CurrentHealth; }

public:
	virtual void Attack(IRace& Target) override;
	virtual void Healing(int MinRange = 10, int MaxRange = 20) override;
	virtual void Defend() override;
	virtual void BoostDamage() override;

protected:
	virtual void TakeDamage(float DamageParameter) override;
};

