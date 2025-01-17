#pragma once

#include "D:\TextingGame\TextingGame\public\Races\BaseRace.h"

#include <memory>

enum EGameState
{
	GAMING,
	WIN,
	LOSE,
	DRAW,

};

enum EAction
{
	ATTACK,
	DEFEND,
	HEALING,
	CHARGE_SUPER_DAMAGE,
};

enum ERace
{
	TERRANS,
	ZERGS,
	PROTOSSES,
};

class GameLogic
{
protected:
	std::unique_ptr<BaseRace> AIRace;
	std::unique_ptr<BaseRace> PlayerRace;

	EAction AIAction;
	EAction PlayerAction;

	EGameState PlayerGameState;

public:
	GameLogic(std::unique_ptr<BaseRace> AIRaceParam, std::unique_ptr<BaseRace> PlayerRaceParam);
	virtual ~GameLogic();

	GameLogic& operator=(GameLogic&& Source) noexcept;

	const EGameState GetPlayerGameState() const { return PlayerGameState; }

public:
	void ShowGameState();

	void Round();
	void FuncPlayerAction(EAction Action);
	void FuncAIAction(EAction Action);
	void EndOfTheGame();
};