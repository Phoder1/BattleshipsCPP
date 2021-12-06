#include <iostream>
#include <string>
#include "Types.h"
#include "Utillities.h"
#include "GamePlayer.h"

using namespace std;

void GamePlayer::ResetHP() {
	_hp = 0;

	for (size_t i = 0; i < Battleship::PlayerShipsTypes; i++)
		_hp += Battleship::PlayerShipsLength[i] * Battleship::PlayerShipsAmount[i];
}
GamePlayer::GamePlayer(string name)
{
	_name = name;
	PlayerCount++;
	_playerNumber = PlayerCount;
	_opponent = nullptr;
	_playerColor = &Color::DefaultColor;

	ResetHP();
}

void GamePlayer::StartGame(GamePlayer* opponent)
{
	//Console::ClearConsole();

	Reset();

	_opponent = opponent;

	FillBattleshipsBoard();
}

string GamePlayer::GetName() {
	return _name;
}

int GamePlayer::GetPlayerNumber() {
	return _playerNumber;
}

void GamePlayer::Reset()
{
	ResetHP();
	GetBoard()->Reset();
}

void GamePlayer::Hit(Vector2Int position)
{
	Board<BoardNode>* board = GetBoard();

	if (!board->IsHit(position)) {
		board->SetHit(position, true);

		if (board->GetHasShip(position))
			_hp--;
	}


	//The rules says the player must declare when a ship has been sanked, so if this option is active, it will automatically surround it with hits
	if (AutoClearAreaAroundSankedShip && board->GetHasShip(position)) {
		Battleship ship = board->GetShipAtPosition(position);
		if (board->IsShipSanked(ship)) {
			for (size_t i = 0; i < ship.GetLength(); i++)
			{
				Vector2Int currentShipTile = ship.GetOrigin() + ship.GetDirection() * i;
				for (size_t x = 0; x < 3; x++)
				{
					for (size_t y = 0; y < 3; y++)
					{
						Vector2Int tempPos = currentShipTile + Vector2Int(x - 1, y - 1);
						if (board->IsInside(tempPos) && !board->IsHit(tempPos)) {
							board->SetHit(tempPos, true);
							if (board->GetHasShip(tempPos))
								_hp--;
						}
					}
				}
			}
		}
	}
}

void GamePlayer::SetHP(int hp)
{
	_hp = hp;
}

int GamePlayer::GetHp()
{
	return _hp;
}

void GamePlayer::SetColor(Color* color)
{
	_playerColor = color;
}

Color* GamePlayer::GetColor()
{
	return _playerColor;
}

int GamePlayer::PlayerCount = 0;
