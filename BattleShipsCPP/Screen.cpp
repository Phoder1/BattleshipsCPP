#include "Screen.h"

Screen::Screen(Vector2Int position, Vector2Int size)
{
}

Screen* Screen::GetCurrentScreen()
{
    return nullptr;
}

void Screen::SetActive()
{
}

void Screen::SetCursorPosition(Vector2Int localPosition)
{
}

Vector2Int Screen::GetCursorLocalPosition()
{
    return Vector2Int();
}

void Screen::PrintAt(Vector2Int position, char symbol, Color color)
{
}

void Screen::ClearScreen()
{
}

void Screen::ClearLine(int lineNumber)
{
}

void Screen::PrintInMiddleOfScreen(string text, bool endl, bool endAtMiddle)
{
}

void Screen::MoveCursorToMiddle()
{
}

Vector2Int Screen::GetSize()
{
    return Vector2Int();
}

void Screen::SetSize(Vector2Int size)
{
}

Vector2Int Screen::GetPosition()
{
    return Vector2Int();
}

void Screen::SetPosition(Vector2Int position)
{
}
