#pragma once
#include <Windows.h>

struct Vector2Int
{
public:
	Vector2Int();
	Vector2Int(int x, int y);
	int X;
	int Y;

	Vector2Int operator+(Vector2Int vector);

	Vector2Int operator*(int scalar);

	static const Vector2Int Zero() { return Vector2Int(0, 0); }
	static Vector2Int Min(Vector2Int vector, Vector2Int maxVector);
};

struct Color
{
private:
	int _color;
public:
	Color();
	Color(int color);


	static int DefaultColor;

	static void SetDefaultColor(int color);
	static void SetDefaultColor(Color color);

	int GetColor();

	static void SetTextColor(int color);
	static void SetTextColor(Color color);

	static int GetCurrentConsoleColorIndex();
	static Color GetCurrentConsoleColor();

	static void ReturnToDefault();

	void ApplyToText();

	static const int BlackIndex = 0;
	static const int DarkBlueIndex = 1;
	static const int DarkGreenIndex = 2;
	static const int DarkCyanIndex = 3;
	static const int DarkRedIndex = 4;
	static const int DarkPinkIndex = 5;
	static const int DarkYellowIndex = 6;
	static const int LightGreyIndex = 7;
	static const int GreyIndex = 8;
	static const int BlueIndex = 9;
	static const int GreenIndex = 10;
	static const int CyanIndex = 11;
	static const int RedIndex = 12;
	static const int PinkIndex = 13;
	static const int YellowIndex = 14;
	static const int WhiteIndex = 15;
	static const Color DarkBlue() { return Color(Color::DarkBlueIndex); }
	static const Color DarkGreen() { return Color(Color::DarkGreenIndex); }
	static const Color DarkCyan() { return Color(Color::DarkCyanIndex); }
	static const Color DarkRed() { return Color(Color::DarkRedIndex); }
	static const Color DarkPink() { return Color(Color::DarkPinkIndex); }
	static const Color DarkYellow() { return Color(Color::DarkYellowIndex); }
	static const Color LightGrey() { return Color(Color::LightGreyIndex); }
	static const Color Grey() { return Color(Color::GreyIndex); }
	static const Color Blue() { return Color(Color::BlueIndex); }
	static const Color Green() { return Color(Color::GreenIndex); }
	static const Color Cyan() { return Color(Color::CyanIndex); }
	static const Color Red() { return Color(Color::RedIndex); }
	static const Color Pink() { return Color(Color::PinkIndex); }
	static const Color Yellow() { return Color(Color::YellowIndex); }
	static const Color White() { return Color(Color::WhiteIndex); }
};

class Board
{
private:
	Vector2Int _size;
	Vector2Int _position;
	Color _color;

	void DrawLine(char start, char line, char seperator, char end, Color color);
	Vector2Int CharCount() { return _size * 2 + Vector2Int(1, 1); }
public:
	Board(Vector2Int position, Vector2Int size, Color color);
	Vector2Int GetSize();
	Vector2Int GetPosition();
	void DrawBoard();
	void MoveCursorToPosition(Vector2Int position);
};

