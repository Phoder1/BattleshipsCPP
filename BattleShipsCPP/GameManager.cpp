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

	_turnNumber = 0;

	_startingPlayer = startingPlayer;
	_secondPlayer = secondPlayer;

	Console::ClearConsole();

	Console::PrintInMiddleOfConsole(startingPlayer->GetName() + " !~VS~! " + secondPlayer->GetName(), true);
	cout << endl;
	Console::PrintInMiddleOfConsole("Use WASD to move, Q/E to rotate and F to select.", true, true);

	//Get players ready for the new egame, and passes to each his opponent
	startingPlayer->StartGame(secondPlayer);

	_startingPlayer->ConfirmEndTurn();


	secondPlayer->StartGame(startingPlayer);

	_secondPlayer->ConfirmEndTurn();

	//Start the actual game loop
	GamePlayer* winningPlayer = StartGameLoop();

	//Do end of game functions here

	//Return the winnig player
	return winningPlayer;
}

bool GameManager::IfWon(GamePlayer* player)
{
	if (_startingPlayer != player)
		return _startingPlayer->GetHp() <= 0;
	else
		return _secondPlayer->GetHp() <= 0;
}
GamePlayer* GameManager::StartGameLoop() {
	//While game is running - will end if a player has won in the return statements
	while (true) {
		ValidateCanPlayTurn();


		//player 1 turn
		StartTurn(_startingPlayer);

		if (IfWon(_startingPlayer))
			return _startingPlayer;

		_startingPlayer->ConfirmEndTurn();

		//player 2 turn
		StartTurn(_secondPlayer);

		if (IfWon(_secondPlayer))
			return _secondPlayer;

		_secondPlayer->ConfirmEndTurn();

		_turnNumber++;
	}
}
/// <summary>
/// Validates that another can be played, for example if the board is full, the player won't have a place to shoot.
/// </summary>
/// <returns></returns>
void GameManager::ValidateCanPlayTurn()
{
	if (_startingPlayer->GetBoard()->IsFullHits() || _secondPlayer->GetBoard()->IsFullHits())
		throw new runtime_error("Boards are completely full, error in win condition detection!");
}

void GameManager::StartTurn(GamePlayer* currentTurnPlayer)
{
	
	Console::PrintInMiddleOfConsole("Turn " + to_string(_turnNumber) + "!", true);

	int opponentHP;
	bool GetAnotherTurn;

	do {
		opponentHP = currentTurnPlayer->GetOpponent()->GetHp();

		currentTurnPlayer->ConfirmStartTurn();

		currentTurnPlayer->PlayTurn();

		GetAnotherTurn = currentTurnPlayer->GetOpponent()->GetHp() < opponentHP;

		if (IfWon(currentTurnPlayer))
			return;

		if (GetAnotherTurn) {
			Console::SetCursorY(0);
			Console::PrintInMiddleOfConsole("Successfully hit! You get another turn!", true);
		}

	} while (GetAnotherTurn);
}

