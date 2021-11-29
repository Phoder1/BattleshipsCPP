#pragma once
#include<iostream> 
#include<list> 
#include "Types.h"
#include "GamePlayer.h"

using namespace std;

class Screen
{
private:

public:
	int* ScreenColor = &Color::DefaultColor;
	virtual void Print() = 0;
};

class GenericScreen : public Screen {
public:
	GenericScreen();
	 void Screen::Print() override;
};
class PlayerScreen : public Screen {
public:
	PlayerScreen(GamePlayer *player);
	 void Screen::Print() override;
};

