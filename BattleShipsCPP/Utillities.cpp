#include <windows.h>
#include <iostream>
#include <string>
#include <sstream>
#include "Utillities.h"

using namespace std;

bool Input::TryParse(string input, int& output)
{
	stringstream ss;

	//Converts the string number to int and loops otherwise
	ss << input;
	ss >> output;

	bool success = !ss.fail();
	return success;
}

void Input::Pause()
{
	cout << endl;
	Console::PrintInMiddleOfConsole(WaitAnyKeyMessage());
	WaitForAnyKey(WaitAnyKeyMessage());
}

bool Input::GetConfirmation(string question)
{
	Vector2Int cursorPos = Console::GetCursorPosition();
	while (true) {
		Console::SetCursorPosition(cursorPos);

		Console::ClearCurrentLine();
		Console::PrintInMiddleOfConsole(question, true, true);

		Console::ClearCurrentLine();
		Console::PrintInMiddleOfConsole("Y/N", true, true);

		Console::ClearCurrentLine();

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

		case 0x51:
			return NavigationKey::RotateCounterClockwise;

		case 0x45:
			return NavigationKey::RotateClockwise;
		}
	}
}

int Input::GetNumber(bool consoleCenter)
{
	if (consoleCenter)
		Console::MoveToCursorToMiddle();

	Vector2Int cursorPos = Console::GetCursorPosition();
	while (true) {
		Console::SetCursorPosition(cursorPos);
		Console::ClearCurrentLine();

		string input;
		cin >> input;

		int output = 0;

		if (TryParse(input, output))
			return output;
	}
}

//Not sure what's happening here, reference: https://www.cplusplus.com/forum/beginner/4533/
TCHAR Input::WaitForAnyKey(string message)
{
	TCHAR  ch;
	DWORD  mode;
	DWORD  count;
	HANDLE hstdin = GetStdHandle(STD_INPUT_HANDLE);

	// Prompt the user
	if (message != "")
		Console::PrintInMiddleOfConsole(message);
	//message = "Press any key to continue...";


	// Switch to raw mode
	GetConsoleMode(hstdin, &mode);
	SetConsoleMode(hstdin, 0);

	// Wait for the user's response
	WaitForSingleObject(hstdin, INFINITE);

	// Read the (single) key pressed
	ReadConsole(hstdin, &ch, 1, &count, NULL);

	// Restore the console to its previous state
	SetConsoleMode(hstdin, mode);

	// Return the key code
	return ch;
}


int MathInt::Modulo(int a, int b) {
	int r = a % b;
	return r < 0 ? r + b : r;
}
