#include <iostream>
#include "GameManager.h"
#include "GamePlayer.h"
#include "Utillities.h"
#include "Types.h"

using namespace std;

GamePlayer* GameManager::PlayGame(GamePlayer* startingPlayer, GamePlayer* secondPlayer) {

	if (startingPlayer == nullptr || secondPlayer == nullptr)
		throw new runtime_error("Nullptr player has been passed to the game manager!");

	_startingPlayer = startingPlayer;
	_secondPlayer = secondPlayer;

	Console::ClearConsole();
	
	Console::PrintInMiddleOfConsole(startingPlayer->GetName() + " !~VS~! " + secondPlayer->GetName(), true);

	//Get players ready for the new game, and passes to each his opponent
	startingPlayer->StartGame(secondPlayer);
	secondPlayer->StartGame(startingPlayer);

	//Start the actual game loop
	GamePlayer* winningPlayer = StartGameLoop();

	//Do end of game functions here

	//Return the winnig player
	return winningPlayer;
}
bool GameManager::ValidateIfWon(GamePlayer* player)
{
	return false;
}
GamePlayer* GameManager::StartGameLoop() {
	//While game is running - will end if a player has won in the return statements
	while (true) {
		ValidateCanPlayTurn();

		_startingPlayer->PlayTurn();

		if (ValidateIfWon(_startingPlayer))
			return _startingPlayer;

		_secondPlayer->PlayTurn();

		if (ValidateIfWon(_secondPlayer))
			return _secondPlayer;
	}
}
/// <summary>
/// Validates that another can be played, for example if the board is full, the player won't have a place to shoot.
/// </summary>
/// <returns></returns>
void GameManager::ValidateCanPlayTurn()
{
	if (_startingPlayer->GetBoard()->IsFullHits())
		throw new runtime_error(_startingPlayer->GetName() + " is full!");

	if (_secondPlayer->GetBoard()->IsFullHits())
		throw new runtime_error(_secondPlayer->GetName() + " is full!");

	return;
}

