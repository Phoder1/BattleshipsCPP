#include "Types.h"
#include "Utillities.h"

BoardNode::BoardNode()
{
	_hit = false;
	_hasShip = false;
}
bool BoardNode::GetHit()
{
	return _hit;
}
void BoardNode::SetHit(bool hit)
{
	_hit = hit;
}
bool BoardNode::GetHasShip()
{
	return _hasShip;
}
void BoardNode::SetHasShip(bool hasShip)
{
	_hasShip = hasShip;
}
void BoardNode::Reset()
{
	_hit = false;
	_hasShip = false;
}
