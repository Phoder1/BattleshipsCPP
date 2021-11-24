#pragma once
#include "GamePlayer.h"
#include <string>

static const string PossibleNames[] = { "Cortana", "C-3PO", "Glados" };
class AIPlayer : public GamePlayer
{
public:
	//using GamePlayer::GamePlayer;
	AIPlayer();
};

