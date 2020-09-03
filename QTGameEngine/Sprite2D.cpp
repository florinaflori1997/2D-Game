#include "Sprite2D.h"

using namespace QTGameEngine;

Sprite2D::Sprite2D()
	:_sprite(new Sprite())
{
	_underlyingItem = _sprite;
}

QTGameEngine::Sprite2D::Sprite2D(QPixmap pixmap)
	:_sprite(new Sprite(pixmap))
{
	_underlyingItem = _sprite;
}

void Sprite2D::addFrame(QPixmap frame, std::string animationName, std::string direction)
{
	if (_orientedAnimation.find(animationName) == _orientedAnimation.end())
	{
		_orientedAnimation[animationName] = std::vector<std::string>();
	}

	std::vector<std::string>& directions = _orientedAnimation[animationName];
	if (std::find(directions.begin(), directions.end(), direction)
			== directions.end())
	{
		directions.push_back(direction);
	}

	_sprite->addFrame(frame, animationName + "_" + direction);
}

Sprite * QTGameEngine::Sprite2D::getSprite()
{
	return _sprite;
}

void Sprite2D::play(std::string animationName, std::string direction)
{
	//if animation exists
	if (_orientedAnimation.find(animationName) != _orientedAnimation.end())
	{
		///qDebug() << "animation found";
		_currentAnimation = animationName;
	}
	else
	{
		///qDebug() << "animation not found";
	}

	//if direction exists
	std::vector<std::string>& directions = _orientedAnimation[animationName];
	if (std::find(directions.begin(), directions.end(), direction)
		!= directions.end())
	{
		///qDebug() << "direction found";
		_sprite->play(animationName + "_" + direction);
	}
	else
	{
		///qDebug() << "direction not found";
	}

}

void QTGameEngine::Sprite2D::setPixmap(QPixmap frame)
{
	_sprite->setPixmap(frame);
}
