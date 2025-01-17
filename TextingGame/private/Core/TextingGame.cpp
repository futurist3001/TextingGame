#include <iostream>
#include <memory>

#include "D:\TextingGame\TextingGame\public\Generic\MyFunctions.h"
#include "D:\TextingGame\TextingGame\public\Core\GameLogic.h"
#include "D:\TextingGame\TextingGame\public\Races\Terrans.h"
#include "D:\TextingGame\TextingGame\public\Races\Zergs.h"
#include "D:\TextingGame\TextingGame\public\Races\Protosses.h"

void InitializeRaces(ERace PlayerRace, ERace AIRace, GameLogic& GameLogicParam);

void StartGame(GameLogic& GameLogicParam)
{
	std::cout << "Please, choose your race where 0 - Terrans, 1 - Zergs, 2 - Protosses." << std::endl;
	int YourRaceChoice;
	int AIRaceChoice = GetRandomNumber<int>(0, 2);

	while (true)
	{
		std::cout << "Your choice: ";
		std::cin >> YourRaceChoice;

		if (YourRaceChoice == 0)
		{
			std::cout << "You chose terrans..." << std::endl;
			InitializeRaces(static_cast<ERace>(YourRaceChoice), static_cast<ERace>(AIRaceChoice), GameLogicParam);

			return;
		}

		else if (YourRaceChoice == 1)
		{
			std::cout << "You chose zergs..." << std::endl;
			InitializeRaces(static_cast<ERace>(YourRaceChoice), static_cast<ERace>(AIRaceChoice),GameLogicParam);

			return;
		}

		else if (YourRaceChoice == 2)
		{
			std::cout << "You chose protosses..." << std::endl;
			InitializeRaces(static_cast<ERace>(YourRaceChoice), static_cast<ERace>(AIRaceChoice),GameLogicParam);

			return;
		}

		std::cout << "You enter wrong symbol! Be attentive!" << std::endl;
	}
}

void InitializeRaces(ERace PlayerRace, ERace AIRace, GameLogic& GameLogicParam)
{
	std::unique_ptr<BaseRace> Player;
	std::unique_ptr<BaseRace> AI;

	switch (PlayerRace)
	{
		case ERace::TERRANS:
			Player = std::make_unique<Terrans>(100.f, 40.f);
			break;

		case ERace::ZERGS:
			Player = std::make_unique<Zergs>(120.f, 20.f);
			break;

		case ERace::PROTOSSES:
			Player = std::make_unique<Protosses>(80.f, 80.f);
			break;

		default:
			throw std::invalid_argument("Invalid Player Race");
	}

	switch (AIRace)
	{
		case ERace::TERRANS:
			AI = std::make_unique<Terrans>(100.f, 40.f);
			std::cout << "You play against terrans." << std::endl;
			break;

		case ERace::ZERGS:
			AI = std::make_unique<Zergs>(120.f, 20.f);
			std::cout << "You play against zergs." << std::endl;
			break;

		case ERace::PROTOSSES:
			AI = std::make_unique<Protosses>(80.f, 80.f);
			std::cout << "You play against protosses." << std::endl;
			break;

		default:
			throw std::invalid_argument("Invalid AI Race");
	}

	GameLogicParam = GameLogic(std::move(Player), std::move(AI));
}

int main()
{
	SetSeedRandom(); // for random number

	std::cout << "Greetings!\nThis is the arena of the strongest of the strongest.\nHere you can battle with computer and find out who is stronger." << std::endl;
	std::cout << "Choose what will you do..." << std::endl;
	std::cout << "Press \"p\" if you want to play and press \"e\" if you afraid and want to exit." << std::endl;

	char Choice;

TryAgain_WrongSymbol:
	std::cout << "Your Choice: ";
	std::cin >> Choice;

	if (Choice == 'e')
	{
		std::cout << "You exit from the game." << std::endl;
		return 0;
	}

	else if (Choice == 'p')
	{// game logic
		GameLogic MyGameLogic(nullptr, nullptr);
		StartGame(MyGameLogic);
		MyGameLogic.Round();
		MyGameLogic.ShowGameState();
	}

	else
	{
		std::cout << "You enter wrong symbol! Be attentive!" << std::endl;
		goto TryAgain_WrongSymbol;
	}

	return 0;
}