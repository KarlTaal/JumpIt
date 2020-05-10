#include "Obstacle.h"
#include <QTimer>
#include <QGraphicsScene>
#include "Game.h"
#include "endscore.h"
#include "replaybutton.h"

#include <QDebug>

extern Game* game;

Obstacle::Obstacle(int random)
{
    width = 30 + random * 30;
    setRect(0,0,width, 50);
    //Connect with timer for moving obstacles
    timer = new QTimer();
    timer->start(5);
    passed = false;
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
}

Obstacle::~Obstacle()
{
    delete timer;
}

void Obstacle::move()
{
    QList<QGraphicsItem*> colliding_items = collidingItems();
    if (colliding_items.size() == 1){
        int score = game->score->getScore();
        QList<QGraphicsItem *> arr = scene()->items();
        EndScore* sc2 = new EndScore(score);
        game->endscore = sc2;
        scene()->addItem(sc2);
        scene()->addWidget(new ReplayButton());
        qDeleteAll(arr);
        return;
    }

    if (x() + width < 400 && !passed){
        game->score->increase(width);
        passed = true;
    }

    setPos(x() - 1, y());
    if (pos().x() < 100){
        scene()->removeItem(this);
        delete this;
    }
}
