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

Board::Board(Vector2Int position, Vector2Int size, Color color)
{
	_color = color;
	_position = position;
	_size = size;
}

Vector2Int Board::GetSize()
{
	return _size;
}

Vector2Int Board::GetPosition()
{
	return _position;
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
	position = Vector2Int::Min(position, _size);
}
