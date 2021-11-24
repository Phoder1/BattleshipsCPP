#include "Types.h"

using namespace std;
Vector2Int::Vector2Int()
{
	X = 0;
	Y = 0;
}

Vector2Int::Vector2Int(int x, int y)
{
	X = x;
	Y = y;
}

Vector2Int Vector2Int::operator+(Vector2Int vector)
{
	return Vector2Int(X + vector.X, Y + vector.Y);
}
Vector2Int Vector2Int::operator*(int scalar)
{
	return Vector2Int(X * scalar , Y * scalar);
}

Vector2Int Vector2Int::Min(Vector2Int a, Vector2Int b)
{
	return Vector2Int(min(a.X,b.X), min(a.Y,b.Y));
}
