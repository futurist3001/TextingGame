#include "D:\TextingGame\TextingGame\public\Races\Protosses.h"

#include <iostream>

Protosses::Protosses(float HP, float AP)
: BaseRace(HP, AP)
{
	DefaultDamage = 20;
	DefendCoefficient = 0.2f;
	BoostDamageCoeficient = 0.10f;
}

Protosses::~Protosses()
{
}

void Protosses::Attack(IRace& Target)
{
	BaseRace::Attack(Target);
	std::cout << "Protosses action: attack." << std::endl;
}

void Protosses::Healing(int MinRange, int MaxRange)
{
	BaseRace::Healing(MinRange, MaxRange);
	std::cout << "Protosses action: healing." << std::endl;
}

void Protosses::Defend()
{
	BaseRace::Defend();
	std::cout << "Protosses action: defend." << std::endl;
}

void Protosses::BoostDamage()
{
	BaseRace::BoostDamage();
	std::cout << "Protosses action: boost damage." << std::endl;
}
