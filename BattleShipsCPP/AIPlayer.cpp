#include <stdlib.h>
#include <string>
#include "Types.h"
#include "Utillities.h"
#include "GamePlayer.h"

using namespace std;

const int AIPlayer::PossibleNamesCount = 3;
const string AIPlayer::PossibleNames[PossibleNamesCount] = { "Cortana", "C-3PO", "Glados" };

AIPlayer* AIPlayer::CreateAIPlayer()
{
	srand(time(NULL));

	int nameIndex = rand() % PossibleNamesCount;
	return new AIPlayer(PossibleNames[nameIndex]);
}
Board<BoardNode>* AIPlayer::GetBoard() {
	return (Board<BoardNode>*)_board;
}
void AIPlayer::SetColor(Color* color)
{
	GamePlayer::SetColor(color);
	_board->SetColor(color);
}
void AIPlayer::DrawWeights()
{
	for (size_t x = 0; x < BoardSizeX; x++)
	{
		for (size_t y = 0; y < BoardSizeY; y++)
		{
			Vector2Int pos = Vector2Int(x, y);
			_board->MoveCursorToPosition(pos);
			cout << _board->GetTile(pos).GetWeight();
		}
	}
}
void AIPlayer::Reset()
{
	GamePlayer::Reset();
}
void AIPlayer::FillBattleshipsBoard() {
	//Randomly place ships

}
void AIPlayer::PlayTurn() {
	//Hit other player

	//refrence to other player
	//_opponent

	//Refrence to other player's board
	//_opponent->GetBoard();
}
void AIPlayer::ConfirmReady() {
	//Keep empty because AI was born ready
}
AIPlayer::~AIPlayer()
{
	delete(_board);
}
