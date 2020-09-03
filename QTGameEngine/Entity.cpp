#include "Entity.h"

using namespace QTGameEngine;

Entity::Entity()
	:_sprite(new Sprite2D())
{
	setPosition(QPointF(0, 0));
	setOrigin(QPointF(64, 64));
}

void Entity::setScene(QGraphicsScene* scene)
{
	_scene = scene;
}

QGraphicsScene* QTGameEngine::Entity::getScene()
{
	return _scene;
}

void QTGameEngine::Entity::setView(QGraphicsView * view)
{
	_view = view;
}

QGraphicsView * QTGameEngine::Entity::getView()
{
	return _view;
}

void Entity::setOrigin(QPointF pos)
{
	_origin = pos;
}

void Entity::setPosition(QPointF pos)
{
	_position = pos;
	if (_sprite != nullptr)
	{
		_sprite->_underlyingItem->setPos(pos - _origin);
	}
}

void Entity::setSprite(EntitySprite* sprite)
{
	sprite->_underlyingItem->setPos(_position - _origin);

	_scene->addItem(sprite->_underlyingItem);
	qDebug() << "sprite added";

	_sprite = sprite;
}

EntitySprite* Entity::sprite()
{
	return _sprite;
}

//used for test
void Entity::addToScene(QGraphicsItem * item)
{
	_scene->addItem(item);
}

void Entity::move()
{
	//qDebug() << _keysPressed->count(Qt::Key_W);

	_moveTimer = new QTimer();
	connect(_moveTimer, SIGNAL(timeout()), this, SLOT(moveStep()));
	_moveTimer->start(10);
}

void Entity::moveStep()
{

	//qDebug() << "player moveStep";
	int wPressed = _keysPressed->count(Qt::Key_W);
	int sPressed = _keysPressed->count(Qt::Key_S);
	int aPressed = _keysPressed->count(Qt::Key_A);
	int dPressed = _keysPressed->count(Qt::Key_D);
	//qDebug() << wPressed;
	if (wPressed)
	{
		//qDebug() << "player pressed W";
		int newx = _position.x();
		int newy = _position.y() - 2;
		setPosition(QPointF(newx, newy));
		_sprite->play("walk", "1");
	}
	if (sPressed)
	{
		//qDebug() << "player pressed S";
		int newx = _position.x();
		int newy = _position.y() + 2;
		setPosition(QPointF(newx, newy));
		_sprite->play("walk", "2");

	}
	if (aPressed)
	{
		//qDebug() << "player pressed A";
		int newx = _position.x() - 2;
		int newy = _position.y();
		setPosition(QPointF(newx, newy));
		_sprite->play("walk", "4");

	}
	if (dPressed)
	{
		//qDebug() << "player pressed D";
		int newx = _position.x() + 2;
		int newy = _position.y();
		setPosition(QPointF(newx, newy));
		_sprite->play("walk", "3");
	}
	if (!wPressed && !aPressed && !sPressed && !dPressed) {
		_sprite->play("walk", "6");
	}
}
