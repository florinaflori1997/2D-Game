#pragma once
#include "QTHeaders.h"


namespace QTGameEngine
{
	class Sprite : public QObject, public QGraphicsItem
	{
		Q_OBJECT
	public:
		//constructors
		Sprite(QGraphicsItem* parent = nullptr);
		Sprite(QPixmap pixmap, QGraphicsItem* parent = nullptr);

		//Frames
		void addFrame(QPixmap frame, std::string animationName);
		void setPixmap(QPixmap frame);

		//Play
		void play(std::string animationName);

		//QGraphicsItem pure virtual fuctions
		virtual QRectF boundingRect() const;
		virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

	public slots:
		void nextFrame();


	private:
		//mapa: nume animatie - vector de poze
		std::unordered_map<std::string,std::vector<QPixmap>> _animation;
		std::string _currentAnimation;
		std::vector<QPixmap> _currentAnimationFrames;
		int _currentFrame;

		QGraphicsPixmapItem* _pixmapItem;

		QTimer* _timer;
	};
}