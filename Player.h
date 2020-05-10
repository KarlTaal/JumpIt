#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>
#include <QObject>
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
    QTimer* timer;
    QTimer* timer2;


public slots:
    void jump();
    void addObstacle();
};

#endif // MYRECT_H
