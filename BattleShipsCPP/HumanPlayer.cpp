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



void HumanPlayer::Reset()
{
	GamePlayer::Reset();
	_board->Reset();
}

void HumanPlayer::FillBattleshipsBoard() {
	_board->SetPosition(Vector2Int(Console::GetConsoleSize().X/2 - BoardSizeX/2, 5));
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

			//Add the new legal ship to the opponentBoard
			_board->AddShip(ship);
		}
	}

	_board->DrawBoard(true, false);
}

void HumanPlayer::PlayTurn() {
	
	Console::ClearConsole();

	Vector2Int position = Vector2Int(BoardSizeX / 2, BoardSizeY / 2);

	Color currentColor = Color::GetCurrentConsoleColor();

	Board* opponentBoard = _opponent->GetBoard();
		DrawBothBoards();

	bool foundALegalPosition = false;
	//Keep tyring until a legal position is found
	while (!foundALegalPosition) {

		//Update the new position and origin
		position = position.Modulo(opponentBoard->Size);

		opponentBoard->DrawBoard(DrawOpponentShips, true);
		opponentBoard->MoveCursorToPosition(position);

		if (opponentBoard->GetHit(position))
			Color::SetTextColor(Color::RedIndex);
		else
			Color::SetTextColor(Color::GreenIndex);

		cout << "O";

		currentColor.ApplyToText();

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
			if (opponentBoard->GetHit(position))
				break;

			foundALegalPosition = true;
			break;
		}
	}

	_opponent->Hit(position);
	opponentBoard->DrawBoard(DrawOpponentShips, true);
}

void HumanPlayer::ConfirmStartTurn() {

	if (typeid(*_opponent) == typeid(AIPlayer))
		return;
	Color currentColor = Color::GetCurrentConsoleColor();

	_playerColor->ApplyToText();
	Input::WaitForAnyKey(GetName() + " press ENTER to start your turn when ready!", VK_RETURN);

	currentColor.ApplyToText();
}
void HumanPlayer::ConfirmEndTurn() {

	Console::SetCursorY(0);
	Input::WaitForAnyKey("Press Enter to pass the turn to " + _opponent->GetName(), VK_RETURN);

	if (IsOpponentHuman())
		Console::ClearConsole();
}

HumanPlayer::~HumanPlayer()
{

}