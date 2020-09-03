#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QDebug>

#include <GameView.h>

#include <Sprite.h>
#include <Entity.h>
#include <SpriteSheet.h>
#include <Sprite2D.h>
#include <Node.h>

using namespace QTGameEngine;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	//crearea view-ului
	GameView* game = new GameView();
	//game->showFullScreen();             --- mutate in clasa
	//game->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	//game->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	//crearea scenei
	QGraphicsScene *scene = new QGraphicsScene();
	scene->setSceneRect(0, 0, game->width(), game->height());
	//adaugarea in view a scenei
	game->setScene(scene);

	//crearea si adaugarea in scena a rect-ului
	QGraphicsRectItem * rect = new QGraphicsRectItem();
	rect->setRect(0, 0, 100, 100);
	scene->addItem(rect);


	QGraphicsRectItem * rect2 = new QGraphicsRectItem();
	rect2->setRect(70, 50, 100, 100);
	//scene->addItem(rect2);

	QTGameEngine::Entity *player = new QTGameEngine::Entity();
	QTGameEngine::SpriteSheet *spriteSheet = new QTGameEngine::SpriteSheet("../graphics/sprite_simple_man.png", 4, 4, 400, 600);
	QTGameEngine::SpriteSheet *spriteSheet2 = new QTGameEngine::SpriteSheet("../graphics/sprite_scott+.png", 8, 2, 108, 140);
	QTGameEngine::Sprite2D *simpleManSprite = new QTGameEngine::Sprite2D(spriteSheet->GetTile(QTGameEngine::Node(0, 0)));
	QTGameEngine::Sprite2D *simpleManSprite2 = new QTGameEngine::Sprite2D(spriteSheet2->GetTile(QTGameEngine::Node(0, 0)));

	//G:\FACULTATE\LICENTA\Aplicatie\MyApplication\GameV1\x64\Debug\graphics\entity

	for (int i = 0; i < 4; ++i)
	{
		simpleManSprite->addFrame(spriteSheet->GetTile(QTGameEngine::Node(i, 0)), "walk", "down");
		simpleManSprite->addFrame(spriteSheet->GetTile(QTGameEngine::Node(i, 1)), "walk", "up");
		simpleManSprite->addFrame(spriteSheet->GetTile(QTGameEngine::Node(i, 2)), "walk", "left");
		simpleManSprite->addFrame(spriteSheet->GetTile(QTGameEngine::Node(i, 3)), "walk", "right");
	}

	for (int j = 0; j < 8; ++j)
	{
		simpleManSprite2->addFrame(spriteSheet2->GetTile(QTGameEngine::Node(j, 0)), "walk", "1");
		simpleManSprite2->addFrame(spriteSheet2->GetTile(QTGameEngine::Node(j, 1)), "walk", "2");
		simpleManSprite2->addFrame(spriteSheet2->GetTile(QTGameEngine::Node(j, 2)), "walk", "3");
		simpleManSprite2->addFrame(spriteSheet2->GetTile(QTGameEngine::Node(j, 3)), "walk", "4");
		simpleManSprite2->addFrame(spriteSheet2->GetTile(QTGameEngine::Node(j, 4)), "walk", "5");
		simpleManSprite2->addFrame(spriteSheet2->GetTile(QTGameEngine::Node(j, 5)), "walk", "6");
	}

	player->setScene(scene);
	player->setView(game);
	player->setOrigin(QPointF(200, 300));
	player->setPosition(QPointF(500, 500));

	player->setSprite(simpleManSprite2);

	player->sprite()->play("walk","1");

	game->addEntity(player);
	//player->addGame(game);

	player->addToScene(rect2);
	qDebug() << game->height() << game->width();

	game->launch();
	return a.exec();
}
