#include <iostream>
#include <Windows.h>
#include "Types.h"
#include "Utillities.h"

using namespace std;

int Color::DefaultColor = 15;

Color::Color()
{
	_color = DefaultColor;
}

Color::Color(int color)
{
	_color = color;
}

void Color::SetDefaultColor(int color)
{
	DefaultColor = color;
}

void Color::SetDefaultColor(Color color)
{
	DefaultColor = color.GetColor();
}

int Color::GetColor()
{
	return _color;
}

void Color::SetTextColor(int color)
{
	SetConsoleTextAttribute(Console::Handle, color);
}

void Color::SetTextColor(Color color)
{
	SetTextColor(color.GetColor());
}

void Color::ReturnToDefault()
{
	SetTextColor(DefaultColor);
}

int Color::GetCurrentConsoleColorIndex()
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(Console::Handle, &info);
	return info.wAttributes;
}

Color Color::GetCurrentConsoleColor()
{
	return Color(GetCurrentConsoleColorIndex());
}

void Color::ApplyToText()
{
	SetTextColor(GetColor());
}