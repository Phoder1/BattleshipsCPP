#include "GamePlayer.h"
#include <stdlib.h>

using namespace std;

AIPlayer::AIPlayer()
{
	srand(time(NULL));

	size_t namesCount = size(PossibleNames);
	int nameIndex = rand() % namesCount;
	_name = PossibleNames[nameIndex];
}
