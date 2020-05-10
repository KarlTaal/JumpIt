#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <QGraphicsRectItem>

class Obstacle:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Obstacle(int random);
    ~Obstacle();
    QTimer* timer;
    bool passed;
    int width;


public slots:
    void move();
};


#endif // OBSTACLE_H
