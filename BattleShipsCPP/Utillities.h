#pragma once
#include <Windows.h>
#include <string>
#include "Types.h"

using namespace std;

class Tests
{
public:
	static void RunAllTest();
	static void ScreenColorPointerTest();
	static void TestAllColors();
};

class Console
{
private:
	static CONSOLE_SCREEN_BUFFER_INFO GetBuffer();
public:
	static HANDLE Handle;
	static Vector2Int GetConsoleSize();
	static void SetCursorPosition(Vector2Int point);
	static Vector2Int GetCursorPosition();
	static void SetCursorX(int x);
	static void SetCursorY(int y);
	static void PrintAt(Vector2Int position, char symbol, Color color);
	static void ClearConsole();
	static void ClearLine(int lineNumber);
	static void ClearCurrentLine();
	static void PrintInMiddleOfConsole(string text);
	static void MoveToCursorToMiddle();
};

class Input {
public:
	static void Pause();
	static bool GetConfirmation();
};

