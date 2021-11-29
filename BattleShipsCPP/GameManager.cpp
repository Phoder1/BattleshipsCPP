#include "GameManager.h"
#include "GamePlayer.h"
#include "Utillities.h"
#include <iostream>

using namespace std;

void GameManager::StartGame(GamePlayer player1, GamePlayer player2) {
	Console::PrintInMiddleOfConsole(player1.GetName() + " !~VS~! " + player2.GetName());
}
