#include <iostream>
#include "Utillities.h"
#include "Types.h"
#include "Board.h"

void Tests::RunAllTest() {
	cout << "Test all colors:" << endl;
	TestAllColors();
	cout << endl;

	Color::ReturnToDefault();
	Input::Pause();
}
void Tests::TestAllColors()
{
	Color::SetTextColor(Color::DarkBlueIndex);
	cout << Color::DarkBlueIndex << " DarkBlueIndex" << endl;

	Color::SetTextColor(Color::DarkGreenIndex);
	cout << Color::DarkGreenIndex << " DarkGreenIndex" << endl;

	Color::SetTextColor(Color::DarkCyanIndex);
	cout << Color::DarkCyanIndex << " DarkCyanIndex" << endl;

	Color::SetTextColor(Color::DarkRedIndex);
	cout << Color::DarkRedIndex << " DarkRedIndex" << endl;

	Color::SetTextColor(Color::DarkPinkIndex);
	cout << Color::DarkPinkIndex << " DarkPinkIndex" << endl;

	Color::SetTextColor(Color::DarkYellowIndex);
	cout << Color::DarkYellowIndex << " DarkYellowIndex" << endl;

	Color::SetTextColor(Color::LightGreyIndex);
	cout << Color::LightGreyIndex << " LightGreyIndex" << endl;

	Color::SetTextColor(Color::GreyIndex);
	cout << Color::GreyIndex << " GreyIndex" << endl;

	Color::SetTextColor(Color::BlueIndex);
	cout << Color::BlueIndex << " BlueIndex" << endl;

	Color::SetTextColor(Color::GreenIndex);
	cout << Color::GreenIndex << " GreenIndex" << endl;

	Color::SetTextColor(Color::CyanIndex);
	cout << Color::CyanIndex << " CyanIndex" << endl;

	Color::SetTextColor(Color::RedIndex);
	cout << Color::RedIndex << " RedIndex" << endl;

	Color::SetTextColor(Color::PinkIndex);
	cout << Color::PinkIndex << " PinkIndex" << endl;

	Color::SetTextColor(Color::YellowIndex);
	cout << Color::YellowIndex << " YellowIndex" << endl;

	Color::ReturnToDefault();
	cout << "ReturnedToDefault" << endl;
}
void Tests::BoardInputTest() {
	Board* board = new Board();
	board->DrawBoard();

	Vector2Int position = Vector2Int::Zero();
	bool selecting = true;

	while (selecting)
	{
		board->MoveCursorToPosition(position);

		switch (Input::GetNavigationKey())
		{
		case NavigationKey::Up:
			//We need to reduce Up and down because the Console positive Y is down
			position = position - Vector2Int::Up();
			break;
		case NavigationKey::Down:
			position = position - Vector2Int::Down();
			break;
		case NavigationKey::Left:
			position = position + Vector2Int::Left();
			break;
		case NavigationKey::Right:
			position = position + Vector2Int::Right();
			break;
		case NavigationKey::Confirm:
			cout << "*";
			break;
		case NavigationKey::Back:
			selecting = false;
			break;
		}

		position = position.Modulo(board->Size);

	}
	if (board != nullptr)
		delete(board);
}