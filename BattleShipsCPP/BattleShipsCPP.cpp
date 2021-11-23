#include <iostream>
#include "GameManager.h"
#include "BattleshipsCPP.h"
#include "GamePlayer.h"
#include "Windows.h"
#include "winuser.h"
using namespace std;

int main()
{
	//The game manager will handle the game itself
	GameManager gameManager = GameManager();

	//The players are created outside the game manager so if they want to play again they don't need to recreate them
	GamePlayer player1 = GamePlayer::ConsoleCreateNewPlayer();
	GamePlayer player2 = GamePlayer::ConsoleCreateNewPlayer();

	bool wantToPlay = true;

	while (wantToPlay)
	{
		gameManager.StartGame(player1, player2);

		char answer;
		bool validAnswer = false;
		POINT point;
		GetCursorPos(&point);

		do {
			SetCursorPos(point.x, point.y);

			cout << endl << "Play again?" << endl;
			cout << "Y/N";

			cin >> answer;

			wantToPlay = answer == 'Y' || answer == 'y';
			validAnswer = wantToPlay || (answer == 'n' || answer == 'N');

		} while (!validAnswer);
	}
}