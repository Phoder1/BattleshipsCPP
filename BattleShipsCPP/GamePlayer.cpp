#include <iostream>
#include <string>
#include "Types.h"
#include "Utillities.h"
#include "GamePlayer.h"

using namespace std;

GamePlayer::GamePlayer(string name)
{
	_name = name;
	PlayerCount++;
	_playerNumber = PlayerCount;
	_opponent = nullptr;
	_hp = 0;

	for (size_t i = 0; i < Battleship::PlayerShipsTypes; i++)
		_hp += Battleship::PlayerShipsLength[i] * Battleship::PlayerShipsAmount[i];
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
}

GamePlayer::~GamePlayer()
{
}

int GamePlayer::GetHp()
{
	return _hp;
}

int GamePlayer::PlayerCount = 0;
