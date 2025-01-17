#pragma once

#include <cstdlib>
#include <ctime>

void SetSeedRandom();

template<typename T>
T GetRandomNumber(int Begin, int End)
{
	return static_cast<T>((rand() % (End - Begin + 1) + Begin));
}