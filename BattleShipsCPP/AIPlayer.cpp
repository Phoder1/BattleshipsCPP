#include <stdlib.h>
#include <string>
#include "Types.h"
#include "Utillities.h"
#include "GamePlayer.h"
#include "AIBrain.h"	
class AIBrain;
using namespace std;

const int AIPlayer::PossibleNamesCount = 3;
const string AIPlayer::PossibleNames[PossibleNamesCount] = { "Cortana", "C-3PO", "Glados" };

AIPlayer* AIPlayer::CreateAIPlayer()
{
	srand(time(NULL));

	int nameIndex = rand() % PossibleNamesCount;
	AIPlayer* pAIPlayer = new AIPlayer(PossibleNames[nameIndex]);
	return pAIPlayer;
}

AIPlayer::AIPlayer(string name) : GamePlayer::GamePlayer(name)
{
	_board = new Board();

}
void AIPlayer::SetColor(Color* color)
{
	GamePlayer::SetColor(color);
	_board->SetColor(color);
}
void AIPlayer::DrawWeights()
{
	for (size_t x = 0; x < BoardSizeX; x++)
	{
		for (size_t y = 0; y < BoardSizeY; y++)
		{
			Vector2Int pos = Vector2Int(x, y);
			_board->MoveCursorToPosition(pos);
		//	cout << _board->GetTile(pos).GetWeight();
		}
	}
}
void AIPlayer::Reset()
{
	GamePlayer::Reset();
	_board->Reset();
}
void AIPlayer::SetOpponent(GamePlayer* p)
{

		GamePlayer::SetOpponent(p);
		_pAIBrain = new AIBrain(this);
		
}
void AIPlayer::FillBattleshipsBoard() {
	//Randomly place ships
	_board->SetPosition(Vector2Int(Console::GetConsoleSize().X / 2 - BoardSizeX / 2, 5));
	Vector2Int position= Vector2Int(rand() % BoardSizeX, rand() % BoardSizeY);;

	const int maxValidDirectionLength = 4; // up,down,left,right
	EightDirection direction = EightDirection::Up;

	//Go over each ship type
	for (size_t typeI = 0; typeI < Battleship::PlayerShipsTypes; typeI++)
	{
		//Save its length
		int size = Battleship::PlayerShipsLength[typeI];
		//And instantiate the amount needed
		for (size_t typeCount = 0; typeCount < Battleship::PlayerShipsAmount[typeI]; typeCount++)
		{
			Battleship ship = Battleship(position, Vector2Int::GetDirection(direction), size);

			//Randomize direction
			direction = static_cast<EightDirection>(rand() % maxValidDirectionLength);

			bool foundALegalPosition = false;
			//Keep tyring until a legal position is found
			while (!foundALegalPosition) {
				position = Vector2Int(rand() % BoardSizeX, rand() % BoardSizeY);
				//Update the new position and origin
				ship.SetDirection(Vector2Int::GetDirection(direction));
				position = position.Modulo(_board->Size);
				ship.SetOrigin(position);

			//	_board->DrawBoard(true, false);
			//	_board->DrawShip(ship);

				bool placedShip = false;
				EightDirection startingDirection = direction;
				do
				{
					// vaild point to place then place it
					if (_board->IsValid(ship)) 
					{
						foundALegalPosition = true;
						_board->AddShip(ship);
						placedShip = true;
					}

					if (placedShip)
						break;

					direction = Vector2Int::Rotate90(direction, false);
					
				} while (direction != startingDirection);// try to check all rotation available to place the ship

				}
			}
		}

	_pAIBrain->ResetWeightBoard();
}
void AIPlayer::PlayTurn() {

	_pAIBrain->Play();
}

void AIPlayer::ConfirmStartTurn() {
	//Keep empty because AI was born ready
}
void AIPlayer::ConfirmEndTurn() {
	//Keep empty because AI was born ready
	if (typeid(*_opponent) == typeid(AIPlayer))
	{
		_board->DrawBoard(true, true);
		Input::Pause();
	}
}


AIPlayer::~AIPlayer()
{
	delete(_pAIBrain);
	delete(_board);
}
