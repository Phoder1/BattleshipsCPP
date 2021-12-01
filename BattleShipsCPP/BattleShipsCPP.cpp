#include "Windows.h"
#include "winuser.h"
#include <iostream>
#include "GameManager.h"
#include "BattleshipsCPP.h"
#include "GamePlayer.h"
#include "Types.h"
#include "Utillities.h"

using namespace std;

int main()
{
	//The game manager will handle the game itself
	GameManager gameManager = GameManager();

	//The players are created outside the game session so if they want to play again they don't need to be recreated
	//Even though you didn't use the new operator, as the name suggests the methods creates new objects
	//So make sure to delete them
	GamePlayer* player1 = HumanPlayer::CreateHumanPlayer();
	GamePlayer* player2 = AIPlayer::CreateAIPlayer();

	do {
		//Start the game
		GamePlayer* winningPlayer = gameManager.PlayGame(player1, player2);

		Console::PrintInMiddleOfConsole(winningPlayer->GetName() + " has won!!", true, true);
		cout << endl;

		//Ask if he wants to keep playing
	} while (Input::GetConfirmation("Play again?"));

	delete(player1);
	delete(player2);
}