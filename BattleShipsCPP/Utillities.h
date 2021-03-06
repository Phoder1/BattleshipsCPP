#pragma once
#include <Windows.h>
#include <string>
#include "Types.h"

using namespace std;

class Tests
{
public:
	static void RunAllTest();
	static void TestAllColors();
	static void BoardInputTest();
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
	static void PrintInMiddleOfConsole(string text, bool endl = false, bool endAtMiddle = false);
	static void MoveToCursorToMiddle();
};

enum class NavigationKey {
	Up,
	Down,
	Left,
	Right,
	Confirm,
	Back,
	RotateClockwise,
	RotateCounterClockwise
};

class Input {
public:
	static bool TryParse(string input, int& output);
	static void Pause();
	static bool GetConfirmation(string question);
	static int GetKey();
	static int GetKeyAsync();
	static NavigationKey GetNavigationKey();
	static int GetNumber(bool consoleCenter = false);
	static TCHAR WaitForAnyKey(string message = "", int keyCode = -1);

	static const string WaitAnyKeyMessage() { return  "Press any key to continue . . ."; }
};

class MathInt {
public:
	static int Modulo(int a, int b);
};
