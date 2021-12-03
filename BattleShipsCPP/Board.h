#pragma once
#include <iostream>
#include "Types.h"
#include "Utillities.h"

using namespace std;

static const int BoardSizeX = 10;
static const int BoardSizeY = 10;

//An option to automatically surround sanked ships with hits
static const bool AutoClearAreaAroundSankedShip = true;

template<typename T>
class Board
{
private:
	static_assert(std::is_base_of<BoardNode, T>::value, "type parameter of this class must derive from BoardNode");
	Vector2Int _position;
	Color* _color;
	T _tiles[BoardSizeX][BoardSizeY];
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

	bool IsHit(Vector2Int position);
	void SetHit(Vector2Int position, bool value);

	bool GetHasShip(Vector2Int position);
	void SetHasShip(Vector2Int position, bool value);

	Battleship GetShipAtPosition(Vector2Int position);
	void DrawBoard(bool visibleShips = false, bool visibleHits = false);
	void MoveCursorToPosition(Vector2Int position);
	bool IsInside(Vector2Int position);

	void DrawShip(Battleship ship);
	bool IsValid(Battleship ship);
	bool IsShipSanked(Battleship ship);

	T GetTile(Vector2Int position);

	bool IsFullHits();

	void AddShip(Battleship ship);

	void Reset();

	~Board();
};


template<typename T>
const Vector2Int Board<T>::Size = Vector2Int(BoardSizeX, BoardSizeY);
template<typename T>
const Vector2Int Board<T>::CharCount = Vector2Int(BoardSizeX * 2 + 1, BoardSizeY * 2 + 1);
template<typename T>
Board<T>::Board(Color* color) {
	Reset();
	if (color == nullptr)
		_color = &Color::DefaultColor;
	else
		_color = color;
	_position = Vector2Int::Zero();
}

template<typename T>
bool Board<T>::IsFullHits()
{
	for (size_t x = 0; x < BoardSizeX; x++)
		for (size_t y = 0; y < BoardSizeY; y++)
			if (!_tiles[x, y]->GetHit())
				return false;

	return true;
}

template<typename T>
void Board<T>::AddShip(Battleship ship)
{
	if (!IsValid(ship))
		throw new runtime_error("Tried to add a ship to an illegal position!");

	for (size_t length = 0; length < ship.GetLength(); length++)
	{
		Vector2Int position = ship.GetOrigin() + ship.GetDirection() * length;
		_tiles[position.X][position.Y].SetHasShip(true);
	}
}

template<typename T>
void Board<T>::DrawLine(char start, char line, char seperator, char end)
{
	int charCount = CharCount.X;
	for (size_t i = 0; i < charCount; i++)
	{
		if (i == 0)
			cout << start;
		else if (i == (charCount - 1))
			cout << end;
		else if (i % 2 == 0)
			cout << seperator;
		else
			cout << line;
	}
}

template<typename T>
Vector2Int Board<T>::GetPosition()
{
	return _position;
}

template<typename T>
void Board<T>::SetPosition(Vector2Int position)
{
	_position = position;
}

template<typename T>
bool Board<T>::IsHit(Vector2Int position)
{
	return _tiles[position.X][position.Y].GetHit();
}

template<typename T>
Vector2Int Board<T>::GetShipDirectionAtPosition(Vector2Int position) {
	if (!GetHasShip(position))
		return Vector2Int::Zero();

	for (size_t x = 0; x < 3; x++) {
		for (size_t y = 0; y < 3; y++) {

			Vector2Int checkedPosition = position + Vector2Int(x - 1, y - 1);

			if (checkedPosition != position && IsInside(checkedPosition) && GetHasShip(checkedPosition))
				return Vector2Int(x - 1, y - 1);
		}
	}
	return Vector2Int::Zero();
}
template<typename T>
Battleship Board<T>::GetShipAtPosition(Vector2Int position) {
	if (!GetHasShip(position))
		return Battleship(position, Vector2Int::Zero(), 0);

	Vector2Int shipDirection = GetShipDirectionAtPosition(position);


	//It's suppose to be technically possible to have a 1 tile ships, even though the official rules doesn't allow it
	if (shipDirection == Vector2Int::Zero())
		return Battleship(position, shipDirection, 1);

	//Now I need to find out the length
	//I already know the position and the position to the direction contains a ship, so I can skip them
	int directionalLength = 2;
	while (true) {

		//Reached ship's end
		if (!GetHasShip(position + shipDirection * directionalLength)) {

			//Turn around and find the total length of the ship
			Vector2Int shipPosition = position + shipDirection * (directionalLength - 1);
			shipDirection = -shipDirection;

			int TotalLength = directionalLength;
			while (true) {
				if (!GetHasShip(shipPosition + shipDirection * directionalLength)) {
					return Battleship(shipPosition, shipDirection, TotalLength);
				}
				TotalLength++;
			}
		}
		directionalLength++;

	}

}

template<typename T>
T Board<T>::GetTile(Vector2Int position) {
	return _tiles[position.X][position.Y];
}

template<typename T>
bool Board<T>::IsShipSanked(Battleship ship) {
	
	for (size_t i = 0; i < ship.GetLength(); i++)
	{
		Vector2Int currentPos = ship.GetOrigin() + ship.GetDirection() * i;
		if (!IsHit(currentPos))
			return false;
	}

	return true;
}
template<typename T>
void Board<T>::SetHit(Vector2Int position, bool value)
{
	_tiles[position.X][position.Y].SetHit(value);
}

template<typename T>
bool Board<T>::GetHasShip(Vector2Int position)
{
	return _tiles[position.X][position.Y].GetHasShip();
}
template<typename T>
void Board<T>::SetHasShip(Vector2Int position, bool value)
{
	_tiles[position.X][position.Y].SetHasShip(value);
}

template<typename T>
Color* Board<T>::GetColor() {
	return _color;
}
template<typename T>
void Board<T>::SetColor(Color* color) {
	_color = color;
}

template<typename T>
void Board<T>::DrawBoard(bool visibleShips, bool visibleHits)
{
	Color currentColor = Color::GetCurrentConsoleColor();
	_color->ApplyToText();
	Console::ClearConsole();
	Console::SetCursorY(_position.Y);
	int charCount = CharCount.Y;
	for (size_t i = 0; i < charCount; i++)
	{
		Console::SetCursorX(_position.X);
		if (i == 0)
			DrawLine('+', '-', '+', '+');
		else if (i == (charCount - 1))
			DrawLine('+', '-', '+', '+');
		else if (i % 2 == 0)
			DrawLine('+', '-', '+', '-');
		else
			DrawLine('|', ' ', '|', '|');

		cout << endl;
	}

	if (visibleHits || visibleShips) {
		for (size_t x = 0; x < BoardSizeX; x++)
			for (size_t y = 0; y < BoardSizeY; y++) {
				MoveCursorToPosition(Vector2Int(x, y));

				bool hasShip = _tiles[x][y].GetHasShip();
				bool wasHit = _tiles[x][y].GetHit();

				if (visibleHits && wasHit) {
					if (hasShip)
						Color::SetTextColor(Color(Color::WhiteIndex, Color::DarkRedIndex));
					else
						Color::SetTextColor(Color::DarkRedIndex);

					cout << '*';
				}
				else if (visibleShips && hasShip) {
					Color::SetTextColor(Color::DarkGreenIndex);
					cout << '%';
				}
			}
	}

	currentColor.ApplyToText();
}

template<typename T>
void Board<T>::MoveCursorToPosition(Vector2Int position)
{
	position = position.Modulo(Size);
	Vector2Int newCursorPosition = _position + position * 2 + Vector2Int(1, 1);
	Console::SetCursorPosition(newCursorPosition);
}

template<typename T>
void Board<T>::DrawShip(Battleship ship)
{
	Color currentColor = Color::GetCurrentConsoleColor();

	bool isValid = IsValid(ship);

	Color::SetTextColor(isValid ? Color::GreenIndex : Color::RedIndex);

	for (size_t i = 0; i < ship.GetLength(); i++)
	{
		Vector2Int position = ship.GetOrigin() + ship.GetDirection() * i;
		MoveCursorToPosition(position);

		cout << '*';
	}

	MoveCursorToPosition(ship.GetOrigin());

	currentColor.ApplyToText();
}

template<typename T>
bool Board<T>::IsValid(Battleship ship)
{
	for (size_t i = 0; i < ship.GetLength(); i++)
	{
		Vector2Int position = ship.GetOrigin() + ship.GetDirection() * i;

		//The rules say your ship cannot be adjacent (even diagonnaly) to any other ship, so I'm checking a 3*3 grid around each purposed point
		for (size_t x = 0; x < 3; x++)
			for (size_t y = 0; y < 3; y++) {
				Vector2Int inspectedPos = position + Vector2Int(x - 1, y - 1);
				if (IsInside(inspectedPos) && GetHasShip(inspectedPos))
					return false;
			}

		if (!IsInside(position))
			return false;
	}
	return true;
}

template<typename T>
void Board<T>::Reset()
{
	for (size_t x = 0; x < BoardSizeX; x++)
		for (size_t y = 0; y < BoardSizeY; y++)
			((BoardNode*)_tiles[x, y])->Reset();
}

template<typename T>
Board<T>::~Board()
{
}

template<typename T>
bool Board<T>::IsInside(Vector2Int position)
{
	return position.X >= 0 && position.Y >= 0 && position.X < Size.X&& position.Y < Size.Y;
}