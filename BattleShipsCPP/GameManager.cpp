#include <iostream>
#include "GameManager.h"
#include "GamePlayer.h"
#include "Utillities.h"
#include "Types.h"

using namespace std;

const int GameManager::MaxTurnsCount = BoardSizeX * BoardSizeY;
GamePlayer* GameManager::PlayGame(GamePlayer* startingPlayer, GamePlayer* secondPlayer) {

	if (startingPlayer == nullptr || secondPlayer == nullptr)
		throw new runtime_error("Nullptr player has been passed to the game manager!");

	_startingPlayer = startingPlayer;
	_secondPlayer = secondPlayer;

	Console::ClearConsole();
	
	Console::PrintInMiddleOfConsole(startingPlayer->GetName() + " !~VS~! " + secondPlayer->GetName(), true);
	Console::PrintInMiddleOfConsole("Use WASD to move, Q/E to rotate and F to select.", true, true);

	//Get players ready for the new game, and passes to each his opponent
	startingPlayer->StartGame(secondPlayer);

	ConfirmPassTurnTo(secondPlayer);

	secondPlayer->StartGame(startingPlayer);

	ConfirmPassTurnTo(startingPlayer);

	//Start the actual game loop
	GamePlayer* winningPlayer = StartGameLoop();

	//Do end of game functions here

	//Return the winnig player
	return winningPlayer;
}
void GameManager::ConfirmPassTurnTo(GamePlayer* player)
{
	Console::ClearConsole();
	Input::WaitForAnyKey("Press Enter to pass the turn to " + player->GetName(), VK_RETURN);
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

		ConfirmPassTurnTo(_secondPlayer);

		_secondPlayer->PlayTurn();

		if (ValidateIfWon(_secondPlayer))
			return _secondPlayer;

		ConfirmPassTurnTo(_startingPlayer);

		_turnNumber++;
	}
}
/// <summary>
/// Validates that another can be played, for example if the board is full, the player won't have a place to shoot.
/// </summary>
/// <returns></returns>
void GameManager::ValidateCanPlayTurn()
{
	if(_turnNumber >= MaxTurnsCount)
		throw new runtime_error(_startingPlayer->GetName() + " is full!");
}

