#pragma once
#include <iostream>
#include <string>
#include "Types.h"

using namespace std;

class GamePlayer
{
private:
	int _playerNumber;
protected:
	string _name;
	Board *_playerBoard;
	GamePlayer *_opponent;
public:
	static int PlayerCount;

	GamePlayer(string name, Board *board);

	virtual void FillBattleshipsBoard() = 0;
	virtual void PlayTurn() = 0;

	int GetPlayerNumber();
	string GetName();
	Board* GetBoard();

	virtual void Reset();
	void StartGame(GamePlayer* opponent);

	~GamePlayer();
};


class HumanPlayer : public GamePlayer
{
public:
	using GamePlayer::GamePlayer;

	void GamePlayer::FillBattleshipsBoard() override;
	void GamePlayer::PlayTurn() override;

	static HumanPlayer* CreateHumanPlayer(Board* board);
};

static const string PossibleNames[] = { "Cortana", "C-3PO", "Glados" };
class AIPlayer : public GamePlayer
{
public:
	using GamePlayer::GamePlayer;

	void GamePlayer::FillBattleshipsBoard() override;
	void GamePlayer::PlayTurn() override;

	static AIPlayer* CreateAIPlayer(Board* board);


};

