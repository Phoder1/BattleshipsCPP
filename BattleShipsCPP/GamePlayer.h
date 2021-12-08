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
	Board* _board;
public:
	Board* GetBoard();

	static const int SpaceBetweenBoards;
	static const int BoardsOffestRight;
	static const int BoardsDrawHeight;
	static const bool DrawOpponentShips;


	void ResetHP();
	static int PlayerCount;

	virtual void FillBattleshipsBoard() = 0;
	virtual void PlayTurn() = 0;
	virtual void ConfirmStartTurn() = 0;
	virtual void ConfirmEndTurn() = 0;
	virtual void SetColor(Color* color);
	virtual void Reset();

	void Hit(Vector2Int position);
	bool IsOpponentAI();
	bool IsOpponentHuman();


	GamePlayer* GetOpponent();
	int GetPlayerNumber();
	string GetName();
	int GetHp();
	Color* GetColor();

	void DrawBothBoards();

	void StartGame(GamePlayer* opponent);

	~GamePlayer();
private:
	void SetHP(int hp);
};


class HumanPlayer : public GamePlayer
{
public:
	using GamePlayer::GamePlayer;

	HumanPlayer(string name) : GamePlayer(name) { }
	void GamePlayer::FillBattleshipsBoard() override;
	void GamePlayer::PlayTurn() override;
	void SetColor(Color* color) override;
	void GamePlayer::ConfirmStartTurn() override;
	void GamePlayer::ConfirmEndTurn() override;
	void Reset() override;

	static HumanPlayer* CreateHumanPlayer();


	~HumanPlayer();
};

class AIPlayer : public GamePlayer
{
	static const int PossibleNamesCount;
	static const string PossibleNames[];

public:
	using GamePlayer::GamePlayer;

	AIPlayer(string name) : GamePlayer(name) { }

	void GamePlayer::FillBattleshipsBoard() override;
	void GamePlayer::PlayTurn() override;
	void SetColor(Color* color) override;
	void GamePlayer::ConfirmStartTurn() override;
	void GamePlayer::ConfirmEndTurn() override;
	void Reset() override;

	void DrawWeights();
	static AIPlayer* CreateAIPlayer();


	~AIPlayer();
};

