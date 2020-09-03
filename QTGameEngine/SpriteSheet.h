#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "QTHeaders.h"
#include "Grid.h"
#include "Node.h"

namespace QTGameEngine {

	class SpriteSheet {
	public:
		SpriteSheet(std::string filepath, int numXTiles, int numYTiles, double tileWidth, double tileHeight);


		//getters
		int numXTiles();
		int numYTiles();
		int tileWidth();
		int tileHeight();
		QPixmap GetTile(Node node);

	private:
		Grid _grid;
		QPixmap _pixmap;
	};

}
