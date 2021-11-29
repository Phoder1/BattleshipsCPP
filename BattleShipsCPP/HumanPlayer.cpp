#include <string>
#include "GamePlayer.h"
#include "Utillities.h"
#include "Types.h"

HumanPlayer* HumanPlayer::CreateHumanPlayer(Board *board) {
	int playerNumber = PlayerCount + 1;
	string name;
	Console::PrintInMiddleOfConsole("Player " + to_string(playerNumber) + ", enter your name: ", true);

	Console::MoveToCursorToMiddle();
	cin >> name;
	cout << endl;
	HumanPlayer *player = new HumanPlayer(name, board);
	return player;
}

void HumanPlayer::StartGame(GamePlayer* opponent)
{
	Console::ClearConsole();

	Console::PrintInMiddleOfConsole("Place ships!");

	Input::Pause();
}
void HumanPlayer::FillBattleshipsBoard() {

}