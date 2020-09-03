#pragma once
#include "QTHeaders.h"

namespace QTGameEngine
{
	class EntitySprite : public QObject
	{
		Q_OBJECT
		friend class Entity;
	public:
		EntitySprite();

		virtual void play(std::string animationName, std::string direction) = 0;
		virtual void setPixmap(QPixmap frame) = 0;
		
	protected:
		QGraphicsItem* _underlyingItem;
	};
}