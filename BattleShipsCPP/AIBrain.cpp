#include "AIBrain.h"
/// <summary>
/// Ai Play Turn
/// </summary>
void AIBrain::Play() {
	// scanning the board for potential plays
	// hit randomly if no potential plays found
	// or target the highest valued point on board
	Vector2Int hitPosition;
	Board* pOpponentBoard = _pOpponent->GetBoard();

	ScanWeightBoard();

	int highestWeightValue = ScanForHighestWeightValue();

	if (highestWeightValue == UnKnownPoint)
	{
		do
		{
			hitPosition = Vector2Int(rand() % BoardSizeX, rand() % BoardSizeY);
		} while (pOpponentBoard->GetHit(hitPosition));
	}
	else
	{
		hitPosition = GetPointFromWeightValue(highestWeightValue);
	}

	_pOpponent->Hit(hitPosition);

}

void AIBrain::ScanWeightBoard()
{
	ScanBoard();

	ScanForPotentialPlays();
}
void AIBrain::ScanForPotentialPlays()
{
	// scanning for hits that hits ships

	for (int i = 0; i < BoardSizeX; i++)
	{
		for (int j = 0; j < BoardSizeY; j++)
		{
			if (_pWeightBoard[i][j] == KnownHit)
			{
				if (IsNeightbourAlsoArehitShip(i, j))
				{
					ScanForHighestWeightValueNodeNeighbour(i, j);
				}
				else
				{
					SuspectNeighbourNodes(i, j);
				}
			}
		}
	}
}
void AIBrain::ScanBoard()
{
	// scanning the board to recieve the information about the current state of the board game
	Board* pOpponentBoard = _pOpponent->GetBoard();
	for (int i = 0; i < BoardSizeX; i++)
	{
		for (int j = 0; j < BoardSizeY; j++)
		{
			if (pOpponentBoard->GetHit(Vector2Int(i, j)))
			{
				if (pOpponentBoard->GetHasShip(Vector2Int(i, j)))
					SetWeightValue(j, i, KnownHit);
				else
					SetWeightValue(j, i, AlreadyHitPoint);
			}
			else
				SetWeightValue(j, i, UnKnownPoint);
		}
	}
}
void AIBrain::SetWeightValue(int x, int y, int amount) {
	_pWeightBoard[x][y] = amount;
}

int AIBrain::ScanForHighestWeightValue()
{
	// scan the board for the highest info weight we have 
	int highestWeightValueOnBoard = UnKnownPoint;
	for (int i = 0; i < BoardSizeX; i++)
	{
		for (int j = 0; j < BoardSizeY; j++)
		{
			if (_pWeightBoard[i][j] > highestWeightValueOnBoard && _pWeightBoard[i][j] != 2)
			{
				highestWeightValueOnBoard = _pWeightBoard[i][j];
			}
		}
	}
	return highestWeightValueOnBoard;
}
void AIBrain::ScanForHighestWeightValueNodeNeighbour(int x, int y)
{
	//checking if they are both in the same row or coulmne and then mark them is they are valid points
	bool AdditiveCheck = false;
	bool SubtractiveCheck = false;
	int index = 1;
	if (IsPointIsInMap(x - 1, y) && _pWeightBoard[x - 1][y] == KnownHit ||
		IsPointIsInMap(x + 1, y) && _pWeightBoard[x + 1][y] == KnownHit)
	{
		do
		{
			if (!AdditiveCheck)
			{
				AdditiveCheck = SuspectNode(x + index, y);
			}
			if (!SubtractiveCheck)
			{
				SubtractiveCheck = SuspectNode(x - index, y);
			}
			index++;
		} while (!AdditiveCheck || !SubtractiveCheck);



	}
	else if (IsPointIsInMap(x, y - 1) && _pWeightBoard[x][y - 1] == KnownHit ||
		IsPointIsInMap(x, y + 1) && _pWeightBoard[x][y + 1] == KnownHit)
	{
		do
		{
			if (!AdditiveCheck)
			{
				AdditiveCheck = SuspectNode(x, y + index);
			}
			if (!SubtractiveCheck)
			{
				SubtractiveCheck = SuspectNode(x, y - index);
			}
			index++;
		} while (!AdditiveCheck || !SubtractiveCheck);
	}
}

bool AIBrain::SuspectNode(int x, int y)
{
	//register Node if can be a potentail ship places
	if (!IsPointIsInMap(x, y))
		return true;

	int currentNodeWeight = _pWeightBoard[x][y];
	if (currentNodeWeight == UnKnownPoint)
	{
		SetWeightValue(x,y,PotentialShipPoint);
		return true;
	}
	else if (currentNodeWeight == KnownHit)
		return false;
	else
		return true;

}

bool AIBrain::IsNeightbourAlsoArehitShip(int x, int y)
{
	// check if 2 or more adjecent nodes are also hit
	bool foundAnotherHit = false;
	if (IsPointIsInMap(x + 1, y))
		foundAnotherHit |= _pWeightBoard[x + 1][y] == KnownHit;
	if (IsPointIsInMap(x - 1, y))
		foundAnotherHit |= _pWeightBoard[x - 1][y] == KnownHit;
	if (IsPointIsInMap(x, y + 1))
		foundAnotherHit |= _pWeightBoard[x][y + 1] == KnownHit;
	if (IsPointIsInMap(x, y - 1))
		foundAnotherHit |= _pWeightBoard[x][y - 1] == KnownHit;

	return foundAnotherHit;
}
Vector2Int AIBrain::GetPointFromWeightValue(int val)
{
	// recieve the first vector point that has  the value same as the  value that is looken for
	for (int i = 0; i < BoardSizeX; i++)
	{
		for (int j = 0; j < BoardSizeY; j++)
		{
			if (_pWeightBoard[i][j] == val)
			{
				return Vector2Int(j, i);
			}
		}
	}
	return Vector2Int(0, 0);
}
bool AIBrain::IsPointIsInMap(int x, int y)
{
	// check if its in board range
	return x >= 0 && x < BoardSizeX&& y >= 0 && y < BoardSizeY;
}
void AIBrain::PotentialPoint(int x, int y)
{
	//if valid point then make it a suspect point for a potential ship
	if (IsPointIsInMap(x, y) && _pWeightBoard[x][y] == UnKnownPoint)
	{
		SetWeightValue(x, y, PotentialShipPoint);
	}
}
void AIBrain::SuspectNeighbourNodes(int x, int y)
{
	//Mark all the nodes around this point as Potentail ship points

	PotentialPoint(x + 1, y);
	PotentialPoint(x - 1, y);
	PotentialPoint(x, y - 1);
	PotentialPoint(x, y + 1);
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

	_pOpponent = pPlayer->GetOpponent();

	_pWeightBoard = new int* [BoardSizeX];

	for (int i = 0; i < BoardSizeX; i++)
	{
		_pWeightBoard[i] = new int[BoardSizeY];
	}
	ResetWeightBoard();

}


void AIBrain::ResetWeightBoard()
{
	for (int i = 0; i < BoardSizeX; i++)
	{
		for (int j = 0; j < BoardSizeY; j++) {

			SetWeightValue(i, j, UnKnownPoint);
		}
	}
}