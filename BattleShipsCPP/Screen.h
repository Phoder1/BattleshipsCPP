#pragma once
#include "Types.h"
#include "Utillities.h"

class Screen
{
private:
	static Screen* _instance;
	Vector2Int position;
	Vector2Int size;
public:
	Screen(Vector2Int position, Vector2Int size);

	Vector2Int GetSize();
	void SetSize(Vector2Int size);

	Vector2Int GetPosition();
	void SetPosition(Vector2Int position);

	static Screen* GetCurrentScreen();

	void SetActive();
	void SetCursorPosition(Vector2Int localPosition);
	Vector2Int GetCursorLocalPosition();

	void PrintAt(Vector2Int position, char symbol, Color color);
	void ClearScreen();
	void ClearLine(int lineNumber);
	void PrintInMiddleOfScreen(string text, bool endl = false, bool endAtMiddle = false);
	void MoveCursorToMiddle();
};

