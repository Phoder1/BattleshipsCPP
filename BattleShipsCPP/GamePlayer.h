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
	Color* _playerColor;
public:
	static int PlayerCount;

	virtual Board<BoardNode>* GetBoard() = 0;
	virtual void FillBattleshipsBoard() = 0;
	virtual void PlayTurn() = 0;
	virtual void ConfirmReady() = 0;

	virtual void SetColor(Color* color);
	virtual void Reset();

	void Hit(Vector2Int position);

	int GetPlayerNumber();
	string GetName();
	int GetHp();
	Color* GetColor();

	void StartGame(GamePlayer* opponent);

	~GamePlayer();
private:
	void SetHP(int hp);
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
	Board<BoardNode>* GamePlayer::GetBoard() override;
	void GamePlayer::FillBattleshipsBoard() override;
	void GamePlayer::PlayTurn() override;
	void SetColor(Color* color) override;
	void GamePlayer::ConfirmReady() override;

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

	Board<BoardNode>* GamePlayer::GetBoard() override;
	void GamePlayer::FillBattleshipsBoard() override;
	void GamePlayer::PlayTurn() override;
	void SetColor(Color* color) override;
	void GamePlayer::ConfirmReady() override;

	void DrawWeights();
	static AIPlayer* CreateAIPlayer();


	~AIPlayer();
};

