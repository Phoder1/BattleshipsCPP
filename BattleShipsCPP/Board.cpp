#include "Utillities.h"
#include <iostream>
#include "Types.h"
using namespace std;

void Board::DrawLine(char start, char line, char seperator, char end, Color color)
{
	Color currentColor = Color::GetCurrentConsoleColor();
	color.ApplyToText();
	int charCount = CharCount().X;
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

Board::Board() {
	Reset();
	_color = Color::DefaultColor;
	_size = GetSize();
	_position = Vector2Int::Zero();
}
Board::Board(Color color)
{
	Reset();
	_color = color;
	_size = GetSize();
	_position = Vector2Int::Zero();
}

Vector2Int Board::GetSize()
{
	return _size;
}

Vector2Int Board::GetPosition()
{
	return _position;
}

void Board::SetPosition(Vector2Int position)
{
	_position = position;
}

void Board::DrawBoard()
{
	Console::ClearConsole();
	Console::SetCursorY(_position.Y);
	int charCount = CharCount().Y;
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
}

void Board::MoveCursorToPosition(Vector2Int position)
{
	position = position.Modulo(_size);
	Vector2Int newCursorPosition = _position + position * 2 + Vector2Int(1, 1);
	Console::SetCursorPosition(newCursorPosition);
}

void Board::DrawShip(Battleship ship)
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
}
bool Board::IsValid(Battleship ship)
{
	for (size_t i = 0; i < ship.GetLength(); i++)
	{
		Vector2Int position = ship.GetOrigin() + ship.GetDirection() * i;
		if (!IsInside(position))
			return false;
	}
	return true;
}

void Board::Reset()
{
	for (size_t x = 0; x < SizeX; x++)
		for (size_t y = 0; y < SizeY; y++)
			_tiles[x, y]->Reset();
}

bool Board::IsInside(Vector2Int position)
{
	return position.X >= 0 && position.Y >= 0 && position.X < _size.X&& position.Y < _size.Y;
}
