#pragma once
#include "GamePlayer.h"
#include "Types.h"
#include "Utillities.h"

class GameManager
{
private:
	static const int MaxTurnsCount;
	GamePlayer* _startingPlayer;
	GamePlayer* _secondPlayer;
	int _turnNumber = 0;
public:
	/// <summary>
	/// Starts the game
	/// </summary>
	GamePlayer* PlayGame(GamePlayer* startingPlayer, GamePlayer* secondPlayer);
	
	bool IfWon(GamePlayer* player);
	GamePlayer* StartGameLoop();
	void ValidateCanPlayTurn();
	void StartTurn(GamePlayer* currentTurnPlayer);
};

