#include "GamePlayer.h"
#include "Utillities.h"
#include <string>

HumanPlayer HumanPlayer::CreateHumanPlayer() {
	int playerNumber = PlayerCount + 1;
	string name;
	Console::PrintInMiddleOfConsole("Player " + to_string(playerNumber) + ", enter your name: ");
	cout << endl;
	Console::MoveToCursorToMiddle();
	cin >> name;
	cout << endl;
	HumanPlayer player = HumanPlayer(name);
	return player;
}