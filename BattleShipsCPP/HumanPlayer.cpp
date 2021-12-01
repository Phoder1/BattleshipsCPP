#include <string>
#include "GamePlayer.h"
#include "Utillities.h"
#include "Types.h"

HumanPlayer* HumanPlayer::CreateHumanPlayer() {
	int playerNumber = PlayerCount + 1;
	string name;
	Console::PrintInMiddleOfConsole("Player " + to_string(playerNumber) + ", enter your name: ", true);

	Console::MoveToCursorToMiddle();
	cin >> name;
	cout << endl;
	HumanPlayer *player = new HumanPlayer(name);
	player->_board = new Board<BoardNode>();
	return player;
}

void HumanPlayer::FillBattleshipsBoard() {
	_board->DrawBoard();

	Input::Pause();
}

void HumanPlayer::PlayTurn() {

}

void HumanPlayer::ValidateCanPlayTurn() {

}