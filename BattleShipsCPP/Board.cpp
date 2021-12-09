#include <iostream>
#include <string>
#include "Types.h"
#include "Utillities.h"
#include "Board.h"

using namespace std;

const Vector2Int Board::Size = Vector2Int(BoardSizeX, BoardSizeY);
const Vector2Int Board::CharCount = Vector2Int(BoardSizeX * 2 + 1, BoardSizeY * 2 + 1);
Board::Board(Color* color) {
	Reset();
	if (color == nullptr)
		_color = &Color::DefaultColor;
	else
		_color = color;
	_position = Vector2Int::Zero();


	
}

bool Board::IsFullHits()
{
	for (size_t x = 0; x < BoardSizeX; x++)
		for (size_t y = 0; y < BoardSizeY; y++)
			if (!_tiles[x][y].GetHit())
				return false;

	return true;
}

void Board::AddShip(Battleship ship)
{
	if (!IsValid(ship))
		throw new runtime_error("Tried to add a ship to an illegal position!");

	for (size_t length = 0; length < ship.GetLength(); length++)
	{
		Vector2Int position = ship.GetOrigin() + ship.GetDirection() * length;
		_tiles[position.X][position.Y].SetHasShip(true);
	}
}

void Board::DrawLine(char start, char line, char seperator, char end)
{
	int charCount = CharCount.X;
	for (size_t i = 0; i < charCount; i++)
	{
		if (i == 0)
			cout << start;
		else if (i == (charCount - 1))
			cout << end;
		else if (i % 2 == 0)
			cout << seperator;
		else
			cout << line;
	}
}

Vector2Int Board::GetPosition()
{
	return _position;
}

void Board::SetPosition(Vector2Int position)
{
	_position = position;
}

bool Board::GetHit(Vector2Int position)
{
	return _tiles[position.X][position.Y].GetHit();
}

Vector2Int Board::GetShipDirectionAtPosition(Vector2Int position) {
	if (!GetHasShip(position))
		return Vector2Int::Zero();

	for (size_t x = 0; x < 3; x++) {
		for (size_t y = 0; y < 3; y++) {

			Vector2Int checkedPosition = position + Vector2Int(x - 1, y - 1);

			if (checkedPosition != position && IsInside(checkedPosition) && GetHasShip(checkedPosition))
				return Vector2Int(x - 1, y - 1);
		}
	}
	return Vector2Int::Zero();
}

Battleship Board::GetShipAtPosition(Vector2Int position) {
	if (!GetHasShip(position))
		return Battleship(position, Vector2Int::Zero(), 0);

	Vector2Int shipDirection = GetShipDirectionAtPosition(position);


	//It's suppose to be technically possible to have a 1 tile ships, even though the official rules doesn't allow it
	if (shipDirection == Vector2Int::Zero())
		return Battleship(position, shipDirection, 1);

	//Now I need to find out the length
	//I already know the position and the position to the direction contains a ship, so I can skip them
	int directionalLength = 2;
	while (true) {

		//Reached ship's end
		if (!GetHasShip(position + shipDirection * directionalLength)) {

			//Turn around and find the total length of the ship
			Vector2Int shipPosition = position + shipDirection * (directionalLength - 1);
			shipDirection = -shipDirection;

			int TotalLength = directionalLength;
			while (true) {
				if (!GetHasShip(shipPosition + shipDirection * TotalLength)) {
					return Battleship(shipPosition, shipDirection, TotalLength);
				}
				TotalLength++;
			}
		}
		directionalLength++;

	}

}

BoardNode Board::GetTile(Vector2Int position) {
	return _tiles[position.X][position.Y];
}

bool Board::IsShipSanked(Battleship ship) {

	for (size_t i = 0; i < ship.GetLength(); i++)
	{
		Vector2Int currentPos = ship.GetOrigin() + ship.GetDirection() * i;
		if (!GetHit(currentPos))
			return false;
	}

	return true;
}

void Board::SetHit(Vector2Int position, bool value)
{
	_tiles[position.X][position.Y].SetHit(value);
}

bool Board::GetHasShip(Vector2Int position)
{
	return _tiles[position.X][position.Y].GetHasShip();
}

void Board::SetHasShip(Vector2Int position, bool value)
{
	_tiles[position.X][position.Y].SetHasShip(value);
}

Color* Board::GetColor() {
	return _color;
}

void Board::SetColor(Color* color) {
	_color = color;
}

void Board::DrawBoard(bool visibleShips, bool visibleHits)
{
	Color currentColor = Color::GetCurrentConsoleColor();
	_color->ApplyToText();
	Console::SetCursorY(_position.Y);
	int charCount = CharCount.Y;
	for (size_t i = 0; i < charCount; i++)
	{
		Console::SetCursorX(_position.X);
		if (i == 0)
			DrawLine('+', '-', '+', '+');
		else if (i == (charCount - 1))
			DrawLine('+', '-', '+', '+');
		else if (i % 2 == 0)
			DrawLine('+', '-', '+', '-');
		else
			DrawLine('|', ' ', '|', '|');

		cout << endl;
	}

	if (visibleHits || visibleShips) {
		for (size_t x = 0; x < BoardSizeX; x++)
			for (size_t y = 0; y < BoardSizeY; y++) {
				MoveCursorToPosition(Vector2Int(x, y));

				bool hasShip = _tiles[x][y].GetHasShip();
				bool wasHit = _tiles[x][y].GetHit();

				if (visibleHits && wasHit) {
					if (hasShip)
						Color::SetTextColor(Color(Color::WhiteIndex, Color::DarkRedIndex));
					else
						Color::SetTextColor(Color::DarkRedIndex);

					cout << '*';
				}
				else if (visibleShips && hasShip) {
					Color::SetTextColor(Color::DarkGreenIndex);
					cout << '%';
				}
			}
	}

	currentColor.ApplyToText();
}

void Board::MoveCursorToPosition(Vector2Int position)
{
	position = position.Modulo(Size);
	Vector2Int newCursorPosition = _position + position * 2 + Vector2Int(1, 1);
	Console::SetCursorPosition(newCursorPosition);
}

void Board::DrawShip(Battleship ship)
{
	Color currentColor = Color::GetCurrentConsoleColor();

	bool isValid = IsValid(ship);

	Color::SetTextColor(isValid ? Color::GreenIndex : Color::RedIndex);

	for (size_t i = 0; i < ship.GetLength(); i++)
	{
		Vector2Int position = ship.GetOrigin() + ship.GetDirection() * i;
		MoveCursorToPosition(position);

		cout << '*';
	}

	MoveCursorToPosition(ship.GetOrigin());

	currentColor.ApplyToText();
}

void Board::DrawTitle(string title)
{
	int x = _position.X + (CharCount.X / 2) - (title.length() / 2);
	Console::SetCursorPosition(Vector2Int(x, _position.Y - 1));

	cout << title;
}

bool Board::IsValid(Battleship ship)
{
	for (size_t i = 0; i < ship.GetLength(); i++)
	{
		Vector2Int position = ship.GetOrigin() + ship.GetDirection() * i;

		//The rules say your ship cannot be adjacent (even diagonnaly) to any other ship, so I'm checking a 3*3 grid around each purposed point
		for (size_t x = 0; x < 3; x++)
			for (size_t y = 0; y < 3; y++) {
				Vector2Int inspectedPos = position + Vector2Int(x - 1, y - 1);
				if (IsInside(inspectedPos) && GetHasShip(inspectedPos))
					return false;
			}

		if (!IsInside(position))
			return false;
	}
	return true;
}

void Board::Reset()
{
	for (size_t x = 0; x < BoardSizeX; x++)
		for (size_t y = 0; y < BoardSizeY; y++)
			_tiles[x][y].Reset();
}

bool Board::IsInside(Vector2Int position)
{
	return position.X >= 0 && position.Y >= 0 && position.X < Size.X&& position.Y < Size.Y;
}

Board::~Board()
{
}