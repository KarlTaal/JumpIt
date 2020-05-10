#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <QGraphicsPixmapItem>

class Obstacle:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Obstacle();
    ~Obstacle();
    QTimer* timer;
    bool passed;
    int width;


public slots:
    void move();
};


#endif // OBSTACLE_H
