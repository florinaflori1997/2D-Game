#pragma once

namespace QTGameEngine
{
	class Node
	{
	public:
		//constructors
		Node();
		Node(int x, int y);

		//getters
		int GetX();
		int GetY();

		//setters
		void SetX(int x);
		void SetY(int y);

	private:
		int _x;
		int _y;
	};

	bool operator==(Node left, Node right);
	bool operator!=(Node left, Node right);
}
