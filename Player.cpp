#include "Player.h"
#include <QKeyEvent>
#include <QTimer>
#include <QGraphicsScene>


Player::Player(){
    QPixmap pm = QPixmap(":/images/pipo.png");
    pm = pm.scaled(75, 75);
    setPixmap(pm);

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
    int maxHeight = 21;

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
    Obstacle* obs = new Obstacle();
    obs->setPos(1200, 435);
    scene()->addItem(obs);
}


