#pragma once
#include <iostream>
#include "Types.h"
#include "Utillities.h"

using namespace std;

template<typename T>
class Board
{
	static_assert(std::is_base_of<BoardNode, T>::value, "type parameter of this class must derive from BoardNode");
private:
	Vector2Int _position;
	Color _color;
	T _tiles[BoardSizeX][BoardSizeY];

	void DrawLine(char start, char line, char seperator, char end, Color color);
public:
	static const Vector2Int Size;
	static const Vector2Int CharCount;
	Board();

	Vector2Int GetPosition();
	void SetPosition(Vector2Int position);

	void DrawBoard(bool visibleShips = false, bool visibleHits = false);
	void MoveCursorToPosition(Vector2Int position);
	bool IsInside(Vector2Int position);

	void DrawShip(Battleship ship);
	bool IsValid(Battleship ship);
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
Board<T>::Board() {
	Reset();
	_color = Color::DefaultColor;
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
		BoardNode node = _tiles[position.X][position.Y];

		node.SetHasShip(true);
	}
}

template<typename T>
void Board<T>::DrawLine(char start, char line, char seperator, char end, Color color)
{
	Color currentColor = Color::GetCurrentConsoleColor();
	color.ApplyToText();
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
	currentColor.ApplyToText();
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
void Board<T>::DrawBoard(bool visibleShips, bool visibleHits)
{
	Console::ClearConsole();
	Console::SetCursorY(_position.Y);
	int charCount = CharCount.Y;
	for (size_t i = 0; i < charCount; i++)
	{
		Console::SetCursorX(_position.X);
		if (i == 0)
			DrawLine('+', '-', '+', '+', _color);
		else if (i == (charCount - 1))
			DrawLine('+', '-', '+', '+', _color);
		else if (i % 2 == 0)
			DrawLine('+', '-', '+', '-', _color);
		else
			DrawLine('|', ' ', '|', '|', _color);

		cout << endl;
	}

	if (visibleHits || visibleShips) {
		for (size_t x = 0; x < BoardSizeX; x++)
			for (size_t y = 0; y < BoardSizeY; y++) {
				MoveCursorToPosition(Vector2Int(x, y));

				if (visibleShips && ((BoardNode*)_tiles[x, y])->GetHasShip())
					cout << '%';
				if (visibleHits && ((BoardNode*)_tiles[x, y])->GetHit())
					cout << '*';
			}
	}
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
	bool isValid = IsValid(ship);
	for (size_t i = 0; i < ship.GetLength(); i++)
	{
		Vector2Int position = ship.GetOrigin() + ship.GetDirection() * i;
		MoveCursorToPosition(position);

		if (isValid)
			Color::SetTextColor(Color::GreenIndex);
		else
			Color::SetTextColor(Color::RedIndex);

		cout << '*';
	}

	MoveCursorToPosition(ship.GetOrigin());
}

template<typename T>
bool Board<T>::IsValid(Battleship ship)
{
	for (size_t i = 0; i < ship.GetLength(); i++)
	{
		Vector2Int position = ship.GetOrigin() + ship.GetDirection() * i;

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
			_tiles[x, y]->Reset();
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