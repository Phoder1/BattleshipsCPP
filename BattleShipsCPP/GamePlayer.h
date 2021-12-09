#pragma once
#include <iostream>
#include <string>
#include "Types.h"
#include "Board.h"

//#include "AIBrain.h"


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
	static const int SpaceBetweenBoards;
	static const int BoardsOffestRight;
	static const int BoardsDrawHeight;
	static const bool DrawOpponentShips;


	void ResetHP();
	static int PlayerCount;

	virtual Board* GetBoard();
	virtual void FillBattleshipsBoard() = 0;
	virtual void PlayTurn() = 0;
	virtual void ConfirmStartTurn() = 0;
	virtual void ConfirmEndTurn() = 0;
	virtual void SetColor(Color* color);
	virtual void Reset();
	virtual void SetOpponent(GamePlayer* opponent);
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

	HumanPlayer(string name) : GamePlayer(name) {
		_board = new Board();
	}
	
	void GamePlayer::FillBattleshipsBoard() override;
	void GamePlayer::PlayTurn() override;
	void SetColor(Color* color) override;
	void GamePlayer::ConfirmStartTurn() override;
	void GamePlayer::ConfirmEndTurn() override;
	void Reset() override;
	static HumanPlayer* CreateHumanPlayer();


	~HumanPlayer();
};
class AIBrain;
class AIPlayer : public GamePlayer
{
private:
	static const int PossibleNamesCount;
	static const string PossibleNames[];

	 AIBrain* _pAIBrain;
public:
	using GamePlayer::GamePlayer;
	AIPlayer(string name);


	void GamePlayer::FillBattleshipsBoard() override;
	void GamePlayer::PlayTurn() override;
	void SetColor(Color* color) override;
	void GamePlayer::ConfirmStartTurn() override;
	void GamePlayer::ConfirmEndTurn() override;
	void Reset() override;
	void SetOpponent(GamePlayer* p) override;
	
	void DrawWeights();
	static AIPlayer* CreateAIPlayer();


	~AIPlayer();
};
