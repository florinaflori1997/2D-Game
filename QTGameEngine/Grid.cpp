#include "Grid.h"

using namespace QTGameEngine;

Grid::Grid()
{
	_xNumCells = 0;
	_xNumCells = 0;
	_cellWidth = 0;
	_cellHeight = 0;
	_width = 0;
	_height = 0;
}

Grid::Grid(int xNumCells, int yNumCells, int cellWidth, int cellHeight)
{
	_xNumCells = xNumCells;
	_xNumCells = yNumCells;
	_cellWidth = cellWidth;
	_cellHeight = cellHeight;
	_width = xNumCells * cellWidth;
	_height = yNumCells * cellHeight;
}

int Grid::GetXNumCells()
{
	return _xNumCells;
}

int Grid::GetYNumCells()
{
	return _yNumCells;
}

int Grid::GetCellWidth()
{
	return _cellWidth;
}

int Grid::GetCellHeight()
{
	return _cellHeight;
}

int Grid::GetWidth()
{
	return _width;
}

int Grid::GetHeight()
{
	return _height;
}

void Grid::SetXNumCells(int xNumCells)
{
	_xNumCells = xNumCells;
	_width = xNumCells * _cellWidth;
}

void Grid::SetYNumCells(int yNumCells)
{
	_yNumCells = yNumCells;
	_height = yNumCells * _cellHeight;
}

void Grid::SetCellWidth(int cellWidth)
{
	_cellWidth = cellWidth;
	_width = _xNumCells * cellWidth;
}

void Grid::SetCellHeight(int cellHeight)
{
	_cellHeight = cellHeight;
	_height = _yNumCells * cellHeight;
}
