#include "GamePlayer.h"

HumanPlayer HumanPlayer::CreateHumanPlayer() {
	int playerNumber = PlayerCount + 1;
	string name;
	cout << "Player " << playerNumber << ", enter your name: ";
	cin >> name;
	cout << endl;
	HumanPlayer player = HumanPlayer(name);
	return player;
}