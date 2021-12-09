#pragma once

#include <queue>
#include "GamePlayer.h";

class AIBrain
{
private:

	Vector2Int _lastPosition;
	GamePlayer* _pPlayer;
	GamePlayer* _pOpponent;
	Board* _pBoard;
	int** _pWeightBoard;

	const int AlreadyHitPoint = -1;
	const int UnKnownPoint = 0;
	const int PotentialShipPoint = 1;
	const int KnownHit = 2;

	void SetWeightValue(int x , int y, int weight);
	
	void ScanWeightBoard();
	void ScanForPotentialPlays();
	void ScanBoard();

	int ScanForHighestWeightValue();
	void ScanForHighestWeightValueNodeNeighbour(int x, int y);
	bool SuspectNode(int x, int y);
	bool IsNeightbourAlsoArehitShip(int x, int y);
	Vector2Int GetPointFromWeightValue(int val);
	bool IsPointIsInMap(int x, int y);
	void PotentialPoint(int x, int y);
	void SuspectNeighbourNodes(int x, int y);
public:

	AIBrain(AIPlayer* pPlayer);
	void ResetWeightBoard();
	void Play();
	~AIBrain();

};



