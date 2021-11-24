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
	Board _board = Board(Vector2Int(20,20), Vector2Int(5, 5), Color::Red());
	_board.DrawBoard();
	Input::Pause();
	//Tests::RunAllTest();

	//The game manager will handle the game itself
	GameManager gameManager = GameManager();

	//The players are created outside the game manager so if they want to play again they don't need to be recreated
	GamePlayer player1 = HumanPlayer::CreateHumanPlayer();
	GamePlayer player2 = AIPlayer::AIPlayer();

	bool wantToPlay = true;

	while (wantToPlay)
	{
		gameManager.StartGame(player1, player2);

		char answer;
		bool validAnswer = false;
		Vector2Int cursorPos = Console::GetCursorPosition();

		do {
			Console::SetCursorPosition(cursorPos);
			Input::Pause();

			Console::ClearConsole();
			Console::PrintInMiddleOfConsole("Play again?");
			cout << endl;
			Console::PrintInMiddleOfConsole("Y/N");
			Console::ClearCurrentLine();
			Console::MoveToCursorToMiddle();
			cin >> answer;

			wantToPlay = answer == 'Y' || answer == 'y';
			validAnswer = wantToPlay || (answer == 'n' || answer == 'N');

		} while (!validAnswer);
	}
}