#include "D:\TextingGame\TextingGame\public\Races\Terrans.h"

#include <iostream>

Terrans::Terrans(float HP, float AP)
: BaseRace(HP, AP)
{
	DefaultDamage = 10;
	DefendCoefficient = 0.3f;
	BoostDamageCoeficient = 0.45f;
}

Terrans::~Terrans()
{
}

void Terrans::Attack(IRace& Target)
{
	BaseRace::Attack(Target);
	std::cout << "Terrans action: attack." << std::endl;
}

void Terrans::Healing(int MinRange, int MaxRange)
{
	BaseRace::Healing(MinRange, MaxRange);
	std::cout << "Terrans action: healing." << std::endl;
}

void Terrans::Defend()
{
	BaseRace::Defend();
	std::cout << "Terrans action: defend." << std::endl;
}

void Terrans::BoostDamage()
{
	BaseRace::BoostDamage();
	std::cout << "Terrans action: boost damage." << std::endl;
}
