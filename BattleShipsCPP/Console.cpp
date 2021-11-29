#include <iostream>
#include "Types.h"
#include "Utillities.h"
#include <string>

using namespace std;

HANDLE Console::Handle = GetStdHandle(STD_OUTPUT_HANDLE);

CONSOLE_SCREEN_BUFFER_INFO Console::GetBuffer() {
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(Handle, &info);
	return info;
}
Vector2Int Console::GetConsoleSize()
{
	CONSOLE_SCREEN_BUFFER_INFO buffer = GetBuffer();

	return Vector2Int(buffer.dwSize.X, buffer.dwSize.Y);
}
void Console::SetCursorPosition(Vector2Int point)
{
	SetConsoleCursorPosition(Handle, { (short)point.X, (short)point.Y });
}

Vector2Int Console::GetCursorPosition()
{

	COORD cursorPos = GetBuffer().dwCursorPosition;
	return Vector2Int(cursorPos.X, cursorPos.Y);
}

void Console::SetCursorX(int x)
{
	SetCursorPosition(Vector2Int(x, GetCursorPosition().Y));
}

void Console::SetCursorY(int y)
{
	SetCursorPosition(Vector2Int(GetCursorPosition().X, y));
}

void Console::PrintAt(Vector2Int position, char symbol, Color color)
{
	SetCursorPosition(position);

	Color currentColor = Color::GetCurrentConsoleColor();
	color.ApplyToText();
	cout << symbol;
	currentColor.ApplyToText();
}

void Console::ClearConsole()
{
	system("cls");

	SetCursorPosition(Vector2Int());
}

void Console::ClearLine(int lineNumber)
{
	Vector2Int currentCursorPosition = GetCursorPosition();
	Vector2Int tempCursorPos = Vector2Int(0, lineNumber);
	SetCursorPosition(tempCursorPos);

	string line = "";
	for (size_t i = 0; i < GetConsoleSize().X; i++)
	{
		line += " ";
	}
	cout << line;

	SetCursorPosition(currentCursorPosition);
}

void Console::ClearCurrentLine()
{
	ClearLine(GetCursorPosition().Y);
}

void Console::PrintInMiddleOfConsole(string text, bool endLine, bool endAtMiddle)
{
	Vector2Int currentCursorPosition = GetCursorPosition();
	Vector2Int startPos = Vector2Int(GetConsoleSize().X / 2 - text.length() / 2, currentCursorPosition.Y);
	SetCursorPosition(startPos);
	cout << text;

	SetCursorPosition(currentCursorPosition);

	if (endLine)
		cout << endl;

	if (endAtMiddle)
		MoveToCursorToMiddle();
}

void Console::MoveToCursorToMiddle()
{
	SetCursorX(GetConsoleSize().X / 2);
}
