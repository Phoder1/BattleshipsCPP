#include <iostream>
#include "GameManager.h"
#include "GamePlayer.h"
#include "Utillities.h"
#include "Types.h"

using namespace std;

void GameManager::StartGame(GamePlayer* player1, GamePlayer* player2) {
	Console::ClearConsole();
	
	Console::PrintInMiddleOfConsole(player1->GetName() + " !~VS~! " + player2->GetName(), true);

	player1->StartGame(player2);
	player2->StartGame(player1);

	Input::Pause();
}
