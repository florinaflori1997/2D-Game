#include "Node.h"

using namespace QTGameEngine;

Node::Node()
{
	_x = 0;
	_y = 0;
}

Node::Node(int x, int y)
{
	_x = x;
	_y = y;
}

int Node::GetX()
{
	return _x;
}

int Node::GetY()
{
	return _y;
}

void Node::SetX(int x)
{
	_x = x;
}

void Node::SetY(int y)
{
	_y = y;
}

bool operator==(Node left, Node right)
{
	return ((left.GetX() == right.GetX()) && (left.GetY() == right.GetY()));
}

bool operator!=(Node left, Node right)
{
	return !((left.GetX() == right.GetX()) && (left.GetY() == right.GetY()));
}
