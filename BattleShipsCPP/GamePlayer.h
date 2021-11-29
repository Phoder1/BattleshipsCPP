#pragma once
#include <iostream>
#include <string>
#include "Types.h"

using namespace std;

class GamePlayer
{
	int _playerNumber;
protected:
	string _name;
	Board *_playerBoard;
	GamePlayer *_opponent;
public:
	GamePlayer(string name, Board *board);

	virtual void StartGame(GamePlayer* opponent) = 0;
	virtual void FillBattleshipsBoard() = 0;

	Board* GetBoard();

	static int PlayerCount;
	string GetName();
	int GetPlayerNumber();

	virtual ~GamePlayer() {
		delete(_playerBoard);
	}
};


class HumanPlayer : public GamePlayer
{
public:
	using GamePlayer::GamePlayer;

	void GamePlayer::StartGame(GamePlayer* opponent) override;
	void GamePlayer::FillBattleshipsBoard() override;

	static HumanPlayer* CreateHumanPlayer(Board* board);
};

static const string PossibleNames[] = { "Cortana", "C-3PO", "Glados" };
class AIPlayer : public GamePlayer
{
public:
	using GamePlayer::GamePlayer;

	void GamePlayer::StartGame(GamePlayer* opponent) override;
	void GamePlayer::FillBattleshipsBoard() override;

	static AIPlayer* CreateAIPlayer(Board* board);
};

