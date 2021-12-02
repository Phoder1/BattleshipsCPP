#include <string>
#include "GamePlayer.h"
#include "Utillities.h"
#include "Types.h"

HumanPlayer* HumanPlayer::CreateHumanPlayer() {
	int playerNumber = PlayerCount + 1;
	string name;
	Console::PrintInMiddleOfConsole("Player " + to_string(playerNumber) + ", enter your name: ", true);

	Console::MoveToCursorToMiddle();
	cin >> name;
	cout << endl;
	HumanPlayer* player = new HumanPlayer(name);
	return player;
}

void HumanPlayer::SetColor(Color* color)
{
	GamePlayer::SetColor(color);
	_board->SetColor(color);
}

HumanPlayer::~HumanPlayer()
{
	delete(_board);
}

void HumanPlayer::FillBattleshipsBoard() {
	_board->SetPosition(Vector2Int(5,5));
	Vector2Int position = Vector2Int(BoardSizeX / 2, BoardSizeY / 2);
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

			bool foundALegalPosition = false;
			//Keep tyring until a legal position is found
			while (!foundALegalPosition) {

				//Update the new position and origin
				ship.SetDirection(Vector2Int::GetDirection(direction));
				position = position.Modulo(_board->Size);
				ship.SetOrigin(position);

				_board->DrawBoard(true, false);
				_board->DrawShip(ship);
				NavigationKey navKey = Input::GetNavigationKey();
				switch (navKey) {
				case NavigationKey::Up:
					position += Vector2Int::Down();
					break;
				case NavigationKey::Down:
					position += Vector2Int::Up();
					break;
				case NavigationKey::Left:
					position += Vector2Int::Left();
					break;
				case NavigationKey::Right:
					position += Vector2Int::Right();
					break;
				case NavigationKey::Confirm:
					if (!_board->IsValid(ship))
						break;
					foundALegalPosition = true;
					break;
				case NavigationKey::Back:
					break;
				case NavigationKey::RotateClockwise:
					direction = Vector2Int::Rotate90(direction, false);
					break;
				case NavigationKey::RotateCounterClockwise:
					direction = Vector2Int::Rotate90(direction, true);
					break;
				}
			}

			//Add the new legal ship to the board
			_board->AddShip(ship);
		}
	}
}

void HumanPlayer::PlayTurn() {
	Input::Pause();
}