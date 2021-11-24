#include "Utillities.h"
#include "Types.h"
#include "Screen.h"

void Tests::RunAllTest() {
	cout << "Test all colors:" << endl;
	TestAllColors();
	cout << endl;

	cout << "Screen color test:" << endl;
	ScreenColorPointerTest();
	cout << endl;


	Color::ReturnToDefault();
}
void Tests::ScreenColorPointerTest() {
	cout << "No changes" << endl;
	PlayerScreen _screen = PlayerScreen();
	int defaultColor = Color::DefaultColor;
	Color::SetTextColor(*_screen.ScreenColor);
	cout << "Hopefully no changes" << endl;

	Color::SetDefaultColor(Color::Red());
	Color::SetTextColor(*_screen.ScreenColor);
	cout << "Hopefully there's changes" << endl;
	Color::ReturnToDefault();
	cout << "Hopefully same as last line" << endl;

	Color::SetDefaultColor(Color::Blue());
	Color::SetTextColor(*_screen.ScreenColor);
	cout << "Hopefully there's changes" << endl;
	Color::ReturnToDefault();
	cout << "Hopefully same as last line" << endl;

	Color::SetDefaultColor(Color::Green());
	Color::SetTextColor(*_screen.ScreenColor);
	cout << "Hopefully there's changes" << endl;
	Color::ReturnToDefault();
	cout << "Hopefully same as last line" << endl;

	int newColor = Color::YellowIndex;
	_screen.ScreenColor = &newColor;

	Color::SetTextColor(*_screen.ScreenColor);
	cout << "Hopefully different from next line" << endl;
	Color::ReturnToDefault();
	cout << "is it?" << endl;

	Color::SetDefaultColor(defaultColor);
	Color::ReturnToDefault();
	cout << "Hopefully same as first line" << endl;
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
