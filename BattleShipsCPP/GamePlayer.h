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

