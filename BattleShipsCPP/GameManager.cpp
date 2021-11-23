#include "GameManager.h"
#include "GamePlayer.h"
#include <iostream>

using namespace std;

void GameManager::StartGame(GamePlayer player1, GamePlayer player2) {
	cout << player1.GetName() << " !~VS~! " << player2.GetName() << endl;
}