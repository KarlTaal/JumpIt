#include "Player.h"
#include <QKeyEvent>
#include <QTimer>
#include <QGraphicsScene>

Player::Player(){
    setRect(0, 0, 50, 50);

    //Connect with timer for jumping
    timer1 = new QTimer();
    timer1->start(25);
    connect(timer1, SIGNAL(timeout()), this, SLOT(jump()));

    //Connect with timer for adding obstacles
    timer2 = new QTimer();
    timer2->start(3000);
    connect(timer2, SIGNAL(timeout()), this, SLOT(addObstacle()));

    m_isJumping = false;
    m_goingUp = false;
    m_jumperHelper = 0;
}

Player::~Player(){
    for(unsigned int i = 0; i < m_obstacles.size(); i++){
       delete m_obstacles[i];
    }
    delete timer1;
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

/*void Player::moveObstacles()
{
    for(unsigned int i = 0; i < m_obstacles.size(); i++){
        m_obstacles[i]->setPos(m_obstacles[i]->x() - 1, m_obstacles[i]->y());
    }
}*/

void Player::addObstacle()
{
    Obstacle* obs = new Obstacle();
    obs->setPos(1200, 500);
    scene()->addItem(obs);
    //m_obstacles.push_back(obs);
}

