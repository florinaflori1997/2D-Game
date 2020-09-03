#pragma once

namespace QTGameEngine
{
	class Grid
	{
	public:
		Grid();
		Grid(int xNumCells, int yNumCells, int cellWidth, int cellHeight);


		//getters
		int GetXNumCells();
		int GetYNumCells();
		int GetCellWidth();
		int GetCellHeight();
		int GetWidth();
		int GetHeight();
		
		//setters
		void SetXNumCells(int xNumCells);
		void SetYNumCells(int yNumCells);
		void SetCellWidth(int cellWidth);
		void SetCellHeight(int cellHeight);

	private:
		int _xNumCells;
		int _yNumCells;
		int _cellWidth;
		int _cellHeight;
		int _width;
		int _height;
	};
}
