#include <iostream>
#include <string>
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

string GamePlayer::GetName() {
	return _name;
}

int GamePlayer::GetPlayerNumber() {
	return _playerNumber;
}

Board* GamePlayer::GetBoard()
{
	return _playerBoard;
}

int GamePlayer::PlayerCount = 0;
