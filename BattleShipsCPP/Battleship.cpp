#include "Types.h"

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
