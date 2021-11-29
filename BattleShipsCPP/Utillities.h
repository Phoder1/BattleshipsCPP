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
	static void DeleteTest();
	void BoardInputTest();
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

enum class NavigationKey {
	Up,
	Down,
	Left,
	Right,
	Confirm,
	Back
};

class Input {
public:
	static void Pause();
	static bool GetConfirmation();
	static int GetKey();
	static int GetKeyAsync();
	static NavigationKey GetNavigationKey();
	static void WaitForNoKeysPressed();
};

class MathInt {
public:
	static int Modulo(int a, int b);
};

//class GarbageCollector {
//public:
//	template <typename T>
//	static void ReleaseArray(T* arr, int size);
//};

//template<typename T>
//inline void GarbageCollector::ReleaseArray(T* arr, int size)
//{
//	for (size_t i = 0; i < size; i++)
//	{
//		delete(&arr[i]);
//	}
//	delete(&arr);
//	delete(arr);
//}
