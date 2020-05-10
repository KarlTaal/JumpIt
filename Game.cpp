#include "Game.h"


Game::Game(QWidget *parent)
{
    //Create a scene
    scene = new QGraphicsScene;
    scene->setSceneRect(0,0,1200, 600);

    //Create an item to put into the scene
    player = new Player();


    //add item to the scene
    scene->addItem(player);

    //make rect focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // add a view
    QGraphicsView* view = new QGraphicsView();
    view->setScene(scene);

    view->setFixedSize(1200, 600);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    score = new Score();
    scene->addItem(score);

    player->setPos(400, 500);


    view->show();

}
