#pragma once
#include <iostream>
#include <string>
#include "Types.h"
#include "Utillities.h"

using namespace std;

static const int BoardSizeX = 10;
static const int BoardSizeY = 10;

//An option to automatically surround sanked ships with hits
static const bool AutoClearAreaAroundSankedShip = true;

class Board
{
private:
	Vector2Int _position;
	Color* _color;
	BoardNode _tiles[BoardSizeX][BoardSizeY];
	Vector2Int GetShipDirectionAtPosition(Vector2Int position);

	void DrawLine(char start, char line, char seperator, char end);
public:
	static const Vector2Int Size;
	static const Vector2Int CharCount;
	Board(Color* color = nullptr);

	Color* GetColor();
	void SetColor(Color* color);

	Vector2Int GetPosition();
	void SetPosition(Vector2Int position);

	bool GetHit(Vector2Int position);
	void SetHit(Vector2Int position, bool value);

	bool GetHasShip(Vector2Int position);
	void SetHasShip(Vector2Int position, bool value);

	Battleship GetShipAtPosition(Vector2Int position);
	void DrawBoard(bool visibleShips = false, bool visibleHits = false);
	void MoveCursorToPosition(Vector2Int position);
	bool IsInside(Vector2Int position);

	void DrawShip(Battleship ship);

	void DrawTitle(string Title);
	bool IsValid(Battleship ship);
	bool IsShipSanked(Battleship ship);

	BoardNode GetTile(Vector2Int position);

	bool IsFullHits();

	void AddShip(Battleship ship);

	void Reset();

	~Board();
};