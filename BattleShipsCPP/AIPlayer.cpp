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
void AIPlayer::FillBattleshipsBoard() {

}
void AIPlayer::PlayTurn() {

}
void AIPlayer::ValidateCanPlayTurn() {

}
AIPlayer::~AIPlayer()
{
	delete(_board);
}
