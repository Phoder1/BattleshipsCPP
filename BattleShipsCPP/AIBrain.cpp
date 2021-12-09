#include "AIBrain.h"
Vector2Int AIBrain::CalculateHit() {


	//refrence to other player
	//_opponent->Hit() <- hit a point on the board
	//_opponent->GetBoard()->GetHit() <- check if this poiunt is already marked as hit
	Vector2Int hitPosition;




	do
	{
		hitPosition = Vector2Int(rand() % BoardSizeX, rand() % BoardSizeY);
	} while (_pPlayer->GetBoard()->GetHit(hitPosition));
	_opponent->Hit(hitPosition);

	if (_opponent->GetBoard()->GetHit(hitPosition)) {

		// add weight to this location <- ai weight system
		_board->GetTile(hitPosition).SetWeight(1);
	}
	Refrence to other player's board
		_opponent->GetBoard();

}
}

AIBrain::~AIBrain()
{
	for (int i = 0; i < BoardSizeX; i++)
	{
		delete[] _pWeightBoard[i];
	}

	delete[] _pWeightBoard;
	delete _pPlayer;
	delete _pWeightBoard;
	_pWeightBoard = nullptr;
}

AIBrain::AIBrain(AIPlayer* pPlayer) {
	_pPlayer = pPlayer;
	 _pBoard = pPlayer->GetBoard();
	 _lastPosition = Vector2Int(0, 0);

	
	_pWeightBoard = new int* [BoardSizeX];

	for (int i = 0; i < BoardSizeX; i++)
	{
		_pWeightBoard[i] = new int[BoardSizeY];

		for (int j = 0; j < BoardSizeY; j++)
			_pWeightBoard[i][j] = 0;
	}
}
