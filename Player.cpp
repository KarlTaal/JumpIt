#include "Player.h"
#include <QKeyEvent>
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>

Player::Player(){
    setRect(0, 0, 50, 50);

    //Connect with timer for jumping
    timer = new QTimer();
    timer->start(25);
    connect(timer, SIGNAL(timeout()), this, SLOT(jump()));

    timer2 = new QTimer();
    QObject::connect(timer2, SIGNAL(timeout()), this, SLOT(addObstacle()));
    timer2->start(2000);

    m_isJumping = false;
    m_goingUp = false;
    m_jumperHelper = 0;
}

Player::~Player(){
    delete timer;
    delete timer2;
}


void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space){
        if (!m_isJumping){
            m_isJumping = true;
            m_goingUp = true;
        }
    }
}

void Player::jump()
{
    int speed = 10;
    int maxHeight = 20;

    if (m_jumperHelper == maxHeight)
        m_goingUp = false;

    if (m_jumperHelper == 0 && !m_goingUp)
        m_isJumping = false;

    if (m_isJumping){
        if (m_goingUp){
            setPos(x(), y()-speed);
            m_jumperHelper++;
        } else{
            setPos(x(), y()+speed);
            m_jumperHelper--;
        }
    }
}


void Player::addObstacle()
{
    int random_number = rand() % 3;
    Obstacle* obs = new Obstacle(random_number);
    obs->setPos(1200, 500);
    scene()->addItem(obs);
}


