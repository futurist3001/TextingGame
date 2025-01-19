#include "D:\TextingGame\TextingGame\public\Races\BaseRace.h"

#include "D:\TextingGame\TextingGame\public\Generic\MyFunctions.h"

BaseRace::BaseRace(float HP, float AM)
: DefaultHealth(HP), Armour(AM)
{
	CurrentHealth = DefaultHealth = HP;
	Armour = AM;
	Damage = DefaultDamage = 10.f;
	Damaged—oefficient = 1.f;
	BoostDamageCoeficient = 0.1f;
	DefendCoefficient = 0.3f;

}

BaseRace::BaseRace()
{
	CurrentHealth = DefaultHealth = 100;
	Armour = 50;
	Damage = DefaultDamage = 10.f;
	Damaged—oefficient = 1.f;
	BoostDamageCoeficient = 0.1f;
	DefendCoefficient = 0.3f;
}

BaseRace::~BaseRace()
{
}

void BaseRace::Attack(IRace& Target) // it will work immediately
{
	if (BaseRace* Enemy = dynamic_cast<BaseRace*>(&Target))
	{
		Enemy->TakeDamage(Damage);
	}

	Damage = DefaultDamage;
}

void BaseRace::TakeDamage(float DamageParameter)
{
	DamageParameter = DamageParameter * Damaged—oefficient;

	if (Armour > 0.f)
	{
		(DamageParameter - Armour) > 0.f ? Armour = 0.f : Armour -= DamageParameter;
	}
	
	else if (CurrentHealth > 0.f)
	{
		(DamageParameter - CurrentHealth) > 0.f ? CurrentHealth = 0.f : CurrentHealth -= DamageParameter;
	}

	Damaged—oefficient = 1.f;
}

void BaseRace::Healing(int MinRange, int MaxRange) // it will work immediately
{
	if (CurrentHealth > 0.f && CurrentHealth < DefaultHealth)
	{
		float RestoredHealth = GetRandomNumber<float>(MinRange, MaxRange);

		(CurrentHealth + RestoredHealth) > DefaultHealth ? CurrentHealth = DefaultHealth : CurrentHealth += RestoredHealth;
	}
}

void BaseRace::Defend() // it will work in the next round
{
	Damaged—oefficient -= DefendCoefficient;
}

void BaseRace::BoostDamage() // it will work in the next round
{
	Damage *= (1 + BoostDamageCoeficient);
}
