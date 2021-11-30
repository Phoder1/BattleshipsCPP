#pragma once
#include "GamePlayer.h"
#include "Types.h"
#include "Utillities.h"

class GameManager
{
private:
	GamePlayer* _startingPlayer;
	GamePlayer* _secondPlayer;
public:
	/// <summary>
	/// Starts the game
	/// </summary>
	GamePlayer* PlayGame(GamePlayer* startingPlayer, GamePlayer* secondPlayer);
	bool ValidateIfWon(GamePlayer* player);
	GamePlayer* StartGameLoop();
	void ValidateCanPlayTurn();
};

