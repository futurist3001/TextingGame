#include "D:\TextingGame\TextingGame\public\Races\Zergs.h"

#include <iostream>

Zergs::Zergs(float HP, float AP)
: BaseRace(HP, AP)
{
	DefaultDamage = 7;
	DefendCoefficient = 0.15f;
	BoostDamageCoeficient = 0.60f;
}

Zergs::~Zergs()
{
}

void Zergs::Attack(IRace& Target)
{
	BaseRace::Attack(Target);
	std::cout << "Zergs action: attack." << std::endl;
}

void Zergs::Healing(int MinRange, int MaxRange)
{
	BaseRace::Healing(MinRange, MaxRange);
	std::cout << "Zergs action: healing." << std::endl;
}

void Zergs::Defend()
{
	BaseRace::Defend();
	std::cout << "Zergs action: defend." << std::endl;
}

void Zergs::BoostDamage()
{
	BaseRace::BoostDamage();
	std::cout << "Zergs action: boost damage." << std::endl;
}
