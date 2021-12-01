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
	GamePlayer(string name);
public:
	static int PlayerCount;

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
	HumanPlayer(string name) : GamePlayer(name) {
		_board = new Board<BoardNode>();
	}
	void GamePlayer::FillBattleshipsBoard() override;
	void GamePlayer::PlayTurn() override;
	void GamePlayer::ValidateCanPlayTurn() override;

	static HumanPlayer* CreateHumanPlayer();

	~HumanPlayer();
};

class AIPlayer : public GamePlayer
{
	static const int PossibleNamesCount;
	static const string PossibleNames[];
	Board<WeightBoardNode>* _board;
public:
	using GamePlayer::GamePlayer;
	AIPlayer() : GamePlayer("") {
		_board = new Board<WeightBoardNode>();
		srand(time(NULL));

		int nameIndex = rand() % PossibleNamesCount;

		_name = PossibleNames[nameIndex];
	}

	void GamePlayer::FillBattleshipsBoard() override;
	void GamePlayer::PlayTurn() override;
	void GamePlayer::ValidateCanPlayTurn() override;

	static AIPlayer* CreateAIPlayer();

	~AIPlayer();
};

