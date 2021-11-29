#include <iostream>
#include "GameManager.h"
#include "BattleshipsCPP.h"
#include "GamePlayer.h"
#include "Windows.h"
#include "winuser.h"
#include "Types.h"
#include "Utillities.h"

using namespace std;

int main()
{
	//Tests::RunAllTest();

	//The game manager will handle the game itself
	GameManager gameManager = GameManager();

	//The players are created outside the game manager so if they want to play again they don't need to be recreated
	GamePlayer player1 = HumanPlayer::CreateHumanPlayer();
	GamePlayer player2 = AIPlayer::AIPlayer();

	bool wantToPlay = true;

	do{
		Console::ClearConsole();
		gameManager.StartGame(player1, player2);
		Input::Pause();
		Console::ClearConsole();
	} while (Input::GetConfirmation());
}