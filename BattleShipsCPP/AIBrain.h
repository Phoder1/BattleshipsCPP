#pragma once
#include "GamePlayer.h"

class AIBrain
{
private:
	Vector2Int _lastPosition;
	GamePlayer* _pPlayer;
	Board<BoardNode>* _pBoard;
	int** _pWeightBoard;

public:

	Vector2Int CalculateHit();

	~AIBrain();
	AIBrain(AIPlayer* pPlayer);

};

