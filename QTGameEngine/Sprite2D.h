#pragma once
#include "QTHeaders.h"
#include "EntitySprite.h"
#include "Sprite.h"
#include "Node.h"

namespace QTGameEngine
{
	class Sprite2D : public EntitySprite
	{
		Q_OBJECT
	public:
		//constructor
		Sprite2D();
		Sprite2D(QPixmap pixmap);

		//
		void addFrame(QPixmap frame, std::string animationName, std::string direction);

		//test
		Sprite* getSprite();

		//play animation
		void play(std::string animationName, std::string direction);
		void setPixmap(QPixmap frame);

	private:
		Sprite* _sprite;

		std::unordered_map<std::string, std::vector<std::string>> _orientedAnimation;
		std::string _currentAnimation;

	};
}