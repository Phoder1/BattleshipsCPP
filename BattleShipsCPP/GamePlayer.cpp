#include <iostream>
#include <string>
#include "Utillities.h"
#include "GamePlayer.h"

using namespace std;

GamePlayer::GamePlayer(string name, Board *board)
{
	_name = name;
	PlayerCount++;
	_playerNumber = PlayerCount;
	_playerBoard = board;
	_opponent = nullptr;
}

void GamePlayer::StartGame(GamePlayer* opponent)
{
	Console::ClearConsole();

	Reset();

	_opponent = opponent;

	FillBattleshipsBoard();

	Input::Pause();
}

string GamePlayer::GetName() {
	return _name;
}

int GamePlayer::GetPlayerNumber() {
	return _playerNumber;
}

void GamePlayer::Reset()
{
	_playerBoard->Reset();
}

GamePlayer::~GamePlayer()
{
	delete _playerBoard;
}

Board* GamePlayer::GetBoard()
{
	return _playerBoard;
}

int GamePlayer::PlayerCount = 0;
