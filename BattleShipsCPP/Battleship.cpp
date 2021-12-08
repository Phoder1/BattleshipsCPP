#include "Types.h"

//For testing purposes
//const int Battleship::PlayerShipsTypes = 2;
//const int Battleship::PlayerShipsLength[PlayerShipsTypes] = { 1, 2 };
//const int Battleship::PlayerShipsAmount[PlayerShipsTypes] = { 1, 1 };


//Official rules
 const int Battleship::PlayerShipsTypes = 4;
 const int Battleship::PlayerShipsLength[PlayerShipsTypes] = { 5,4,3,2 };
 const int Battleship::PlayerShipsAmount[PlayerShipsTypes] = { 1,1,2,1 };

Battleship::Battleship(Vector2Int origin, Vector2Int direction, int length) {
	_origin = origin;
	_direction = direction;
	_length = length;
}
Vector2Int Battleship::GetOrigin() {
	return _origin;
}
Vector2Int Battleship::GetDirection() {
	return _direction;
}
int Battleship::GetLength() {
	return _length;
}
void Battleship::SetOrigin(Vector2Int origin) {
	_origin = origin;
}
void Battleship::SetDirection(Vector2Int direction) {
	_direction = direction;
}
void Battleship::SetLength(int length) {
	_length = length;
}
