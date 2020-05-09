#include "Obstacle.h"
#include <QTimer>
#include <QGraphicsScene>

Obstacle::Obstacle()
{
    setRect(0,0,10, 50);
    //Connect with timer for moving obstacles
    timer = new QTimer();
    timer->start(5);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
}

Obstacle::~Obstacle()
{
    delete timer;
}

void Obstacle::move()
{
    setPos(x() - 1, y());
    if (pos().x() < 100){
        scene()->removeItem(this);
        delete this;
    }
}
