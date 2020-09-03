#pragma once
#include "QTHeaders.h"
#include "Entity.h"

namespace QTGameEngine 
{
	class GameView : public QGraphicsView
	{
	public:
		//constructors
		GameView();
		GameView(Entity* player);

		//launch game
		void launch();

		void keyPressEvent(QKeyEvent* event);
		void keyReleaseEvent(QKeyEvent* event);
		std::set<int>* getKeysPressed();

		void addEntity(Entity* entity);

	private:
		Entity* _player;


		std::set<int>* _keysPressed;
		QTimer* _moveTimer;
	};
}