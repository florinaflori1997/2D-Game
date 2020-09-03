#include "GameView.h"

using namespace QTGameEngine;

GameView::GameView()
	:_player(new Entity()),
	_keysPressed(new std::set<int>())
{

}

GameView::GameView(Entity * player)
	:_player(player)
{

}

void GameView::launch()
{
	setFixedWidth(800);
	setFixedHeight(600);
	show();
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	_player->_keysPressed = _keysPressed;
	_player->move();
}

void GameView::keyPressEvent(QKeyEvent *event)
{
	if (!event->isAutoRepeat()) {
		_keysPressed->insert(event->key());
		qDebug() << event->key();
	}
	//_player->move(_keysPressed);
}

void GameView::keyReleaseEvent(QKeyEvent *event)
{
	if (!event->isAutoRepeat()) {
		_keysPressed->erase(event->key());
		qDebug() << event->key();
	}
	//_player->move(_keysPressed);
}

std::set<int>* GameView::getKeysPressed()
{
	return _keysPressed;
}

void GameView::addEntity(Entity* entity)
{
	_player = entity;
}
