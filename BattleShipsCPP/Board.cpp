//#include <iostream>
//#include "Types.h"
//#include "Utillities.h"
//using namespace std;
//
//template<typename T>
//Board<T>::Board<T>() {
//	Reset();
//	_color = Color::DefaultColor;
//	_size = GetSize();
//	_position = Vector2Int::Zero();
//}
//
//template<typename T>
//bool Board<T>::IsFullHits()
//{
//	for (size_t x = 0; x < BoardSizeX; x++)
//		for (size_t y = 0; y < BoardSizeY; y++)
//			if (!_tiles[x, y]->GetHit())
//				return false;
//	
//	return true;
//}
//
//template<typename T>
//void Board<T>::DrawLine(char start, char line, char seperator, char end, Color color)
//{
//	Color currentColor = Color::GetCurrentConsoleColor();
//	color.ApplyToText();
//	int charCount = CharCount().X;
//	for (size_t i = 0; i < charCount; i++)
//	{
//		if (i == 0)
//			cout << start;
//		else if (i == (charCount - 1))
//			cout << end;
//		else if (i % 2 == 0)
//			cout << seperator;
//		else
//			cout << line;
//	}
//	currentColor.ApplyToText();
//}
//
//template<typename T>
//Vector2Int Board<T>::GetSize()
//{
//	return _size;
//}
//
//template<typename T>
//Board<T>* Board<T>::CreateBoard()
//{
//	return new Board<T>();
//}
//
//template<typename T>
//Vector2Int Board<T>::GetPosition()
//{
//	return _position;
//}
//
//template<typename T>
//void Board<T>::SetPosition(Vector2Int position)
//{
//	_position = position;
//}
//
//template<typename T>
//void Board<T>::DrawBoard()
//{
//	Console::ClearConsole();
//	Console::SetCursorY(_position.Y);
//	int charCount = CharCount().Y;
//	for (size_t i = 0; i < charCount; i++)
//	{
//		Console::SetCursorX(_position.X);
//		if (i == 0)
//			DrawLine('+', '-', '+', '+', _color);
//		else if (i == (charCount - 1))
//			DrawLine('+', '-', '+', '+', _color);
//		else if (i % 2 == 0)
//			DrawLine('+', '-', '+', '-', _color);
//		else
//			DrawLine('|', ' ', '|', '|', _color);
//
//		cout << endl;
//	}
//}
//
//template<typename T>
//void Board<T>::MoveCursorToPosition(Vector2Int position)
//{
//	position = position.Modulo(_size);
//	Vector2Int newCursorPosition = _position + position * 2 + Vector2Int(1, 1);
//	Console::SetCursorPosition(newCursorPosition);
//}
//
//template<typename T>
//void Board<T>::DrawShip(Battleship ship)
//{
//	bool isValid = IsValid(ship);
//	for (size_t i = 0; i < ship.GetLength(); i++)
//	{
//		Vector2Int position = ship.GetOrigin() + ship.GetDirection() * i;
//		MoveCursorToPosition(position);
//
//		if (isValid)
//			Color::SetTextColor(Color::GreenIndex);
//		else
//			Color::SetTextColor(Color::RedIndex);
//
//		cout << '*';
//	}
//}
//
//template<typename T>
//bool Board<T>::IsValid(Battleship ship)
//{
//	for (size_t i = 0; i < ship.GetLength(); i++)
//	{
//		Vector2Int position = ship.GetOrigin() + ship.GetDirection() * i;
//		if (!IsInside(position))
//			return false;
//	}
//	return true;
//}
//
//template<typename T>
//void Board<T>::Reset()
//{
//	for (size_t x = 0; x < BoardSizeX; x++)
//		for (size_t y = 0; y < BoardSizeY; y++)
//			_tiles[x, y]->Reset();
//}
//
//template<typename T>
//Board<T>::~Board()
//{
//}
//
//template<typename T>
//bool Board<T>::IsInside(Vector2Int position)
//{
//	return position.X >= 0 && position.Y >= 0 && position.X < _size.X&& position.Y < _size.Y;
//}
