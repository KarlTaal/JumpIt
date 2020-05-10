#include "Score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    m_score = 0;
    setPlainText(QString("Score: ") + QString::number(m_score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 24));
}

void Score::increase(int add)
{
    m_score += add;
    setPlainText(QString("Score: ") + QString::number(m_score));
}

int Score::getScore()
{
    return m_score;
}
