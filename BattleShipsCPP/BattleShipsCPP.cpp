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
	GamePlayer* player1 = HumanPlayer::CreateHumanPlayer(new Board(Color::Green()));
	GamePlayer* player2 = AIPlayer::CreateAIPlayer(new Board(Color::Red()));

	do {
		//Start the game
		GamePlayer* winningPlayer = gameManager.PlayGame(player1, player2);

		Console::PrintInMiddleOfConsole(winningPlayer->GetName() + " has won!!", true, true);

		//Ask if he wants to keep playing
	} while (Input::GetConfirmation("Play again?"));

	if (player1 != nullptr)
		delete(player1);

	if (player2 != nullptr)
		delete(player2);
}