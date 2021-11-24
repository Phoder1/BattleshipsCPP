#include "Utillities.h"
#include <iostream>
#include <string>

void Input::Pause()
{
	cout << endl;
	Vector2Int currentCursorPosition = Console::GetCursorPosition();
	string text = "Press any key to continue . . .";
	Vector2Int startPos = Vector2Int(Console::GetConsoleSize().X / 2 - text.length() / 2, currentCursorPosition.Y);
	Console::SetCursorPosition(startPos);

	system("pause");
}

bool Input::GetConfirmation()
{
	return true;
}
