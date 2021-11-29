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
	//Tests::RunAllTest();

	//The game manager will handle the game itself
	GameManager gameManager = GameManager();

	//The players are created outside the game session so if they want to play again they don't need to be recreated
	GamePlayer* player1 = HumanPlayer::CreateHumanPlayer(new Board(Color::Green()));
	GamePlayer* player2 = AIPlayer::CreateAIPlayer(new Board(Color::Red()));

	do {
		//Start the game
		gameManager.StartGame(player1, player2);

		//Ask if he wants to keep playing
	} while (Input::GetConfirmation("Play again?"));

	delete(player1);
	delete(player2);
}