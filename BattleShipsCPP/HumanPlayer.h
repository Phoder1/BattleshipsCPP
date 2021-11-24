#pragma once
#include "GamePlayer.h"
#include <string>

class HumanPlayer : public GamePlayer
{
public:
	using GamePlayer::GamePlayer;
	static HumanPlayer CreateHumanPlayer();
};

