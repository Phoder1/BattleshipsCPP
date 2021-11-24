#pragma once
#include <iostream>
#include <string>

using namespace std;

class GamePlayer
{
	int _playerNumber;
protected:
	GamePlayer();
	string _name;
public:
	static int PlayerCount;
	GamePlayer(string name);
	string GetName();
	int GetPlayerNumber();
};


class HumanPlayer : public GamePlayer
{
public:
	using GamePlayer::GamePlayer;
	static HumanPlayer CreateHumanPlayer();
};

static const string PossibleNames[] = { "Cortana", "C-3PO", "Glados" };
class AIPlayer : public GamePlayer
{
public:
	//using GamePlayer::GamePlayer;
	AIPlayer();
};

