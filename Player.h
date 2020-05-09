#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>
#include <QObject>
#include <vector>
#include "Obstacle.h"

class Player: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent* event);
    Player();
    ~Player();
    bool m_isJumping;
    bool m_goingUp;
    int m_jumperHelper;
    std::vector<Obstacle*> m_obstacles;
    QTimer* timer1;
    QTimer* timer2;



public slots:
    void jump();
    void addObstacle();
};

#endif // MYRECT_H
