#pragma once
#include<iostream> 
#include<list> 
#include "Types.h"

using namespace std;

class Screen
{
private:

public:
	int* ScreenColor = &Color::DefaultColor;
	virtual void Print() = 0;
};

class PlayerScreen : public Screen {
public:
	 void Screen::Print() override;
};

