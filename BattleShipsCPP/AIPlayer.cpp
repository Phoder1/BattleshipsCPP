#include <stdlib.h>
#include "Types.h"
#include "Utillities.h"
#include "GamePlayer.h"

using namespace std;

AIPlayer* AIPlayer::CreateAIPlayer(Board* board)
{
	srand(time(NULL));

	size_t namesCount = size(PossibleNames);
	int nameIndex = rand() % namesCount;
	return new AIPlayer(PossibleNames[nameIndex], board);
}

void AIPlayer::StartGame(GamePlayer* opponent)
{
	Console::ClearConsole();

	cout << "Generated ships!";

	Input::Pause();
}
void AIPlayer::FillBattleshipsBoard() {

}
