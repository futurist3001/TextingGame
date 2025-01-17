#pragma once

class IRace
{
public:
	virtual ~IRace() = default;

protected:
	virtual void Attack(IRace& Target) = 0;
	virtual void TakeDamage(float DamageParameter) = 0;
	virtual void Healing(int MinRange, int MaxRange) = 0;
	virtual void Defend() = 0;
	virtual void BoostDamage() = 0;

};