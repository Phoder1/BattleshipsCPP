#pragma once
#include <iostream>
#include <string>
#include "Types.h"
#include "Board.h"

using namespace std;

class GamePlayer
{
private:
	int _playerNumber;
	int _hp;
protected:
	string _name;
	GamePlayer* _opponent;
public:
	static int PlayerCount;

	GamePlayer(string name);

	virtual void FillBattleshipsBoard() = 0;
	virtual void PlayTurn() = 0;
	virtual void ValidateCanPlayTurn() = 0;

	int GetPlayerNumber();
	string GetName();
	int GetHp();

	virtual void Reset();
	void StartGame(GamePlayer* opponent);

	~GamePlayer();
};


class HumanPlayer : public GamePlayer
{
private:
	Board<BoardNode>* _board;
public:
	using GamePlayer::GamePlayer;

	void GamePlayer::FillBattleshipsBoard() override;
	void GamePlayer::PlayTurn() override;
	void GamePlayer::ValidateCanPlayTurn() override;

	static HumanPlayer* CreateHumanPlayer();
};

class AIPlayer : public GamePlayer
{
	static const int PossibleNamesCount;
	static const string PossibleNames[];
public:
	using GamePlayer::GamePlayer;

	void GamePlayer::FillBattleshipsBoard() override;
	void GamePlayer::PlayTurn() override;
	void GamePlayer::ValidateCanPlayTurn() override;

	static AIPlayer* CreateAIPlayer();
};

