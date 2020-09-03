#pragma once
#include "QTHeaders.h"
#include "EntitySprite.h"

//test
#include "Sprite2D.h"

namespace QTGameEngine
{
	class Entity: public QObject
	{
		Q_OBJECT
	public:
		//constructor
		Entity();

		//scene set and get
		void setScene(QGraphicsScene* scene);
		QGraphicsScene* getScene();
		//view set and get
		void setView(QGraphicsView* view);
		QGraphicsView* getView();

		void setOrigin(QPointF pos);
		void setPosition(QPointF pos);

		//sprite set and get
		void setSprite(EntitySprite* sprite);
		EntitySprite* sprite();

		//test
		void addToScene(QGraphicsItem* item);
		//void addGame(GameView* game);

		//
		void move();

		std::set<int>* _keysPressed;
	public slots:
		void moveStep();

	private:
		QPointF _position;
		QPointF _origin;

		int _lives;
		int _maxLives;
		double _health;
		double _maxHealth;

		EntitySprite* _sprite;
		QGraphicsScene* _scene;
		QGraphicsView* _view;

		QTimer* _moveTimer;

		//GameView* _game;

	};
}