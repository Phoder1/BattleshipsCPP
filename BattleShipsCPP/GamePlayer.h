#pragma once
#include <iostream>
#include <string>

using namespace std;

class GamePlayer
{
private:
	string _name;
	int _playerNumber;
public:
	static int PlayerCount;
	GamePlayer(string name);
	static GamePlayer ConsoleCreateNewPlayer();
	string GetName();
	int GetPlayerNumber();
};

