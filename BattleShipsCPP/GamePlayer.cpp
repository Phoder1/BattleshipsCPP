#include <iostream>
#include <string>
#include "GamePlayer.h"

using namespace std;

GamePlayer::GamePlayer(string name)
{
	_name = name;
	PlayerCount++;
	_playerNumber = PlayerCount;
}

GamePlayer GamePlayer::ConsoleCreateNewPlayer() {
	int playerNumber = PlayerCount + 1;
	string name;
	cout << "Player " << playerNumber << ", enter your name: ";
	cin >> name;
	cout << endl;
	GamePlayer player = GamePlayer(name);
	return player;
}

string GamePlayer::GetName() {
	return _name;
}

int GamePlayer::GetPlayerNumber() {
	return _playerNumber;
}

int GamePlayer::PlayerCount = 0;
