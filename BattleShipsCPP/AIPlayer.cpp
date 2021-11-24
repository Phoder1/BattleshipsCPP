#include "AIPlayer.h"
#include <stdlib.h>

using namespace std;

AIPlayer::AIPlayer()
{
	srand(time(NULL));

	int namesCount = size(PossibleNames);
	int nameIndex = rand() % namesCount;
	_name = PossibleNames[nameIndex];
}
