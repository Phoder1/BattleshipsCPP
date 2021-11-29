#include <windows.h>
#include <iostream>
#include <string>
#include "Utillities.h"

using namespace std;

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
	Vector2Int cursorPos = Console::GetCursorPosition();
	while (true) {
		Console::SetCursorPosition(cursorPos);

		Console::ClearCurrentLine();
		Console::PrintInMiddleOfConsole("Play again?");
		cout << endl;

		Console::ClearCurrentLine();
		Console::PrintInMiddleOfConsole("Y/N");
		cout << endl;

		Console::ClearCurrentLine();
		Console::MoveToCursorToMiddle();

		char answer;
		cin >> answer;

		if (answer == 'Y' || answer == 'y')
			return true;
		else if (answer == 'N' || answer == 'n')
			return false;
	}
}
int  Input::GetKey()
{
	int input = 0;

	while (input == 0) {
		input = GetKeyAsync();
	}

	return input;
}

int Input::GetKeyAsync()
{
	//Starts checking from 8 because everything before that is mouse input, Refrence: https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
	for (int i = 8; i <= 256; i++)
		//Not sure why I need to add the & 0x7FFF, Reference: https://stackoverflow.com/questions/2246502/c-key-input-in-windows-console
		if (GetAsyncKeyState(i) & 0x7FFF)
			return i;

	return -1;
}

NavigationKey Input::GetNavigationKey()
{
	while (true)
	{
		SHORT key = GetKey();

		//Refrence: https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
		switch (key)
		{
		case VK_UP:
			//W
		case 87:
			return NavigationKey::Up;

		case VK_DOWN:
			//S
		case 83:
			return NavigationKey::Down;

		case VK_LEFT:
			//A
		case 65:
			return NavigationKey::Left;

		case VK_RIGHT:
			//D
		case 0x44:
			return NavigationKey::Right;

			//Enter
		case VK_RETURN:
			return NavigationKey::Confirm;

			//Backspace
		case VK_BACK:
		case VK_ESCAPE:
			return NavigationKey::Back;
		}
	}
}

void Input::WaitForNoKeysPressed()
{
	while (true)
	{
		int key = GetKeyAsync();
		cout << key;
		if (key == -1)
			return;
		cout << ".";
	}
}

int MathInt::Modulo(int a, int b) {
	int r = a % b;
	return r < 0 ? r + b : r;
}
