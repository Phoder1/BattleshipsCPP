#include <iostream>
#include <string>
#include "GamePlayer.h"

using namespace std;

GamePlayer::GamePlayer()
{
	_name = "No name assigned";
	PlayerCount++;
	_playerNumber = PlayerCount;
}

GamePlayer::GamePlayer(string name)
{
	_name = name;
	PlayerCount++;
	_playerNumber = PlayerCount;
}

string GamePlayer::GetName() {
	return _name;
}

int GamePlayer::GetPlayerNumber() {
	return _playerNumber;
}

int GamePlayer::PlayerCount = 0;
