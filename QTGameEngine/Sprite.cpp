#include "Sprite.h"

using namespace QTGameEngine;

//constructor
Sprite::Sprite(QGraphicsItem* parent)
	:QGraphicsItem(parent)
{
	_pixmapItem = new QGraphicsPixmapItem(QPixmap("graphics/no_picture.png"),this);

	//initialization
	_timer = new QTimer(this);
	_currentFrame = 0;

	//_playingAnimation = "";
	//_playingAnimationFPS = -1;
}

//constructor
Sprite::Sprite(QPixmap pixmap, QGraphicsItem * parent)
	:QGraphicsItem(parent)
{
	_pixmapItem = new QGraphicsPixmapItem(pixmap,this);

	//initialization
	_timer = new QTimer(this);
	_currentFrame = 0;

	//_playingAnimation = "";
	//_playingAnimationFPS = -1;
}

void Sprite::addFrame(QPixmap frame, std::string animationName)
{
	if (_animation.find(animationName) == _animation.end())
	{
		_animation[animationName] = std::vector<QPixmap>();
		_animation[animationName].push_back(frame);
	}
	else
	{
		_animation[animationName].push_back(frame);
	}
}

void QTGameEngine::Sprite::setPixmap(QPixmap frame)
{
	_pixmapItem->setPixmap(frame);
}

void Sprite::play(std::string animationName)
{
	double fps = 20;
	assert(_animation.find(animationName) != _animation.end());
	//if (_animation.find(animationName) != _animation.end())
	//{
		_currentAnimation = animationName;
		_currentAnimationFrames = _animation[animationName];
		_currentFrame = 0;

		///qDebug() << _currentAnimationFrames.size();

		nextFrame();
		connect(_timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
		_timer->start((1 / fps)*1000); //seconds in ms
	//}

}

//pure virtual function of QGraphicsItem
QRectF Sprite::boundingRect() const
{
	return _pixmapItem->boundingRect();
}

//pure virtual function of QGraphicsItem
void Sprite::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	//does nothing because:
	//the painting is done somewhere else (in QGraphicsPixmapItem)
	//_pixmapItem->paint(painter, option, widget);
}

void Sprite::nextFrame()
{
	if (_currentFrame >= _currentAnimationFrames.size())
	{
		_currentFrame = 0;
	}
	else
	{
		setPixmap(_currentAnimationFrames[_currentFrame]);
		//emit updateFrame();
		++_currentFrame;
	}
}