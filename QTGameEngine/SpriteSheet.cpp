#include "SpriteSheet.h"
#include <QString>

using namespace QTGameEngine;

SpriteSheet::SpriteSheet(std::string filepath, int numXTiles, int  numYTiles, double tileWidth, double tileHeight)
	:_grid(numXTiles, numYTiles, tileHeight, tileWidth)
{
	QFile* file = new QFile(QString::fromStdString(filepath));
	if (!file->exists())
	{
		qDebug() << "File not found: " << QString::fromStdString(filepath);
	}
	else
	{
		qDebug() << "File found: " << QString::fromStdString(filepath);
	}

	_pixmap.load(QString::fromStdString(filepath));
}

int QTGameEngine::SpriteSheet::numXTiles()
{
	return _grid.GetXNumCells();
}

int QTGameEngine::SpriteSheet::numYTiles()
{
	return _grid.GetYNumCells();
}

int QTGameEngine::SpriteSheet::tileWidth()
{
	return _grid.GetCellHeight();
}

int QTGameEngine::SpriteSheet::tileHeight()
{
	return _grid.GetCellWidth();
}

QPixmap SpriteSheet::GetTile(Node node)
{
	return _pixmap.copy(node.GetX() * tileWidth(), node.GetY() * tileHeight(),
		tileWidth(), tileHeight());
}
