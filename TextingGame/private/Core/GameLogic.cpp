#include "D:\TextingGame\TextingGame\public\Core\GameLogic.h"

#include <iostream>
#include "D:\TextingGame\TextingGame\public\Generic\MyFunctions.h"

GameLogic::GameLogic(std::unique_ptr<BaseRace> AIRaceParam, std::unique_ptr<BaseRace> PlayerRaceParam)
: AIRace(std::move(AIRaceParam)), PlayerRace(std::move(PlayerRaceParam))
{
	PlayerGameState = EGameState::GAMING;
	AIAction = EAction::ATTACK;
	PlayerAction = EAction::ATTACK;
}

GameLogic::~GameLogic()
{
}

GameLogic& GameLogic::operator=(GameLogic&& Source) noexcept
{
	if (this != &Source)
	{
		AIRace.reset();
		PlayerRace.reset();

		AIRace = std::move(Source.AIRace);
		PlayerRace = std::move(Source.PlayerRace);
	}

	return *this;
}

void GameLogic::ShowGameState()
{
	switch (PlayerGameState)
	{
		case EGameState::WIN:
			std::cout << std::endl;
			std::cout << "YOU WIN!" << std::endl;
			break;

		case EGameState::LOSE:
			std::cout << std::endl;
			std::cout << "YOU ARE DEFEATED!" << std::endl;
			break;

		case EGameState::DRAW:
			std::cout << std::endl;
			std::cout << "YOU HAVE DRAW!" << std::endl;
			break;

		default:
			std::cout << std::endl;
			std::cout << "Something went wrong..." << std::endl;
			break;
	}
}

void GameLogic::Round()
{
	int AIActionChoice;
	int PlayerActionChoice;

	do
	{
		int Attempts = 0;
		do
		{
			AIActionChoice = GetRandomNumber<int>(0, 3);

			if (AIActionChoice == 0)
				break;

			Attempts++;
		} while (Attempts < 2);

TryAgain:
		std::cout << "Choose your action, where 0 - attack, 1 - defend, 2 - healing, 3 - charge super damage." << std::endl;
		PlayerActionChoice = -1;
		std::cin >> PlayerActionChoice;

		if (std::cin.fail())
		{
			std::cout << "Invalid input. Please enter a number between 0 and 3." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			goto TryAgain;
		}

		if (PlayerActionChoice == 0 || PlayerActionChoice == 1 || PlayerActionChoice == 2 || PlayerActionChoice == 3)
		{// some action from player and from AI

			FuncPlayerAction(static_cast<EAction>(PlayerActionChoice));
			FuncAIAction(static_cast<EAction>(AIActionChoice));

			std::cout << "Your current health: " << PlayerRace->GetCurrentHealth() << std::endl;
			std::cout << "AI current health: " << AIRace->GetCurrentHealth() << std::endl;

			EndOfTheGame();
		}

		else
		{
			std::cout << "Invalid input. Please enter a number between 0 and 3." << std::endl;
			goto TryAgain;
		}
	} while (PlayerGameState == EGameState::GAMING);
}

void GameLogic::FuncPlayerAction(EAction Action)
{
	switch (Action)
	{
		case EAction::ATTACK:
			std::cout << "Your action: " << std::endl;
			PlayerRace->Attack(*AIRace);
			break;

		case EAction::DEFEND:
			std::cout << "Your action: " << std::endl;
			PlayerRace->Defend();
			break;

		case EAction::HEALING:
			std::cout << "Your action: " << std::endl;
			PlayerRace->Healing();
			break;

		case EAction::CHARGE_SUPER_DAMAGE:
			std::cout << "Your action: " << std::endl;
			PlayerRace->BoostDamage();
			break;

		dafault:
			throw std::invalid_argument("Invalid Player Action");
	}
}

void GameLogic::FuncAIAction(EAction Action)
{
	switch (Action)
	{
		case EAction::ATTACK:
			std::cout << "AI action: " << std::endl;
			AIRace->Attack(*PlayerRace);
			break;

		case EAction::DEFEND:
			std::cout << "AI action: " << std::endl;
			AIRace->Defend();
			break;

		case EAction::HEALING:
			std::cout << "AI action: " << std::endl;
			AIRace->Healing();
			break;

		case EAction::CHARGE_SUPER_DAMAGE:
			std::cout << "AI action: " << std::endl;
			AIRace->BoostDamage();
			break;

		dafault:
			throw std::invalid_argument("Invalid AI Action");
	}
}

void GameLogic::EndOfTheGame()
{
	if (PlayerRace->GetCurrentHealth() <= 0.01f && AIRace->GetCurrentHealth() > 0.01f)
		PlayerGameState = EGameState::LOSE;

	else if (PlayerRace->GetCurrentHealth() > 0.01f && AIRace->GetCurrentHealth() <= 0.01f)
		PlayerGameState = EGameState::WIN;

	if (PlayerRace->GetCurrentHealth() <= 0.01f && AIRace->GetCurrentHealth() <= 0.01f)
		PlayerGameState = EGameState::DRAW;
}
