#include "Types.h"
#include "Utillities.h"

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

Vector2Int Vector2Int::operator*(Vector2Int vector)
{
	return Vector2Int(X * vector.X, Y * vector.Y);
}

Vector2Int Vector2Int::operator/(Vector2Int vector)
{
	return Vector2Int(X / vector.X, Y / vector.Y);
}

Vector2Int Vector2Int::operator+(Vector2Int vector)
{
	return Vector2Int(X + vector.X, Y + vector.Y);
}
void Vector2Int::operator+=(Vector2Int vector)
{
	X = X + vector.X;
	Y = Y + vector.Y;
}
Vector2Int Vector2Int::operator-(Vector2Int vector)
{
	return Vector2Int(X - vector.X, Y - vector.Y);
}
void Vector2Int::operator-=(Vector2Int vector)
{
	X = X - vector.X;
	Y = Y - vector.Y;
}
Vector2Int Vector2Int::Modulo(Vector2Int vector)
{
	int newX = MathInt::Modulo(X, vector.X);
	int newY = MathInt::Modulo(Y, vector.Y);

	return Vector2Int(newX, newY);
}
Vector2Int Vector2Int::operator-()
{
	return Vector2Int(-X,-Y);
}
bool Vector2Int::operator==(Vector2Int vector)
{
	return X == vector.X && Y == vector.Y;
}
bool Vector2Int::operator!=(Vector2Int vector)
{
	return X != vector.X || Y != vector.Y;
}
Vector2Int Vector2Int::operator*(int scalar)
{
	return Vector2Int(X * scalar, Y * scalar);
}

Vector2Int Vector2Int::operator/(int scalar)
{
	return Vector2Int(X / scalar, Y / scalar);
}

void Vector2Int::Clamp(Vector2Int vectorMin, Vector2Int vectorMax)
{
	X = max(min(X, vectorMax.X), vectorMin.X);
	Y = max(min(Y, vectorMax.Y), vectorMin.Y);

}

const Vector2Int Vector2Int::GetDirection(EightDirection direction)
{
	switch (direction)
	{
	case EightDirection::Up:
		return Vector2Int(0, 1);
	case EightDirection::Down:
		return Vector2Int(0, -1);
	case EightDirection::Left:
		return Vector2Int(-1, 0);
	case EightDirection::right:
		return Vector2Int(1, 0);
	case EightDirection::UpLeft:
		return Vector2Int(-1, 1);
	case EightDirection::UpRight:
		return Vector2Int(1, 1);
	case EightDirection::DownLeft:
		return Vector2Int(-1, -1);
	case EightDirection::DownRight:
		return Vector2Int(1, -1);
	default:
		throw new exception();
	}
}

const EightDirection Vector2Int::Rotate45(EightDirection direction, bool clockwise)
{
	if (clockwise) {
		switch (direction)
		{
		case EightDirection::Up:
			return EightDirection::UpRight;

		case EightDirection::UpRight:
			return EightDirection::right;

		case EightDirection::right:
			return EightDirection::DownRight;

		case EightDirection::DownRight:
			return EightDirection::Down;

		case EightDirection::Down:
			return EightDirection::DownLeft;

		case EightDirection::DownLeft:
			return EightDirection::Left;

		case EightDirection::Left:
			return EightDirection::UpLeft;

		case EightDirection::UpLeft:
			return EightDirection::Up;

		default:
			throw new exception();
		}
	}
	else {
		switch (direction)
		{
		case EightDirection::Up:
			return EightDirection::UpLeft;

		case EightDirection::UpLeft:
			return EightDirection::Left;

		case EightDirection::Left:
			return EightDirection::DownLeft;

		case EightDirection::DownLeft:
			return EightDirection::Down;

		case EightDirection::Down:
			return EightDirection::DownRight;

		case EightDirection::DownRight:
			return EightDirection::right;

		case EightDirection::right:
			return EightDirection::UpRight;

		case EightDirection::UpRight:
			return EightDirection::Up;

		default:
			throw new exception();
		}
	}
}

const EightDirection Vector2Int::Rotate90(EightDirection direction, bool clockwise)
{
	return Rotate45(Rotate45(direction, clockwise), clockwise);
}

Vector2Int Vector2Int::Min(Vector2Int a, Vector2Int b)
{
	return Vector2Int(min(a.X, b.X), min(a.Y, b.Y));
}
