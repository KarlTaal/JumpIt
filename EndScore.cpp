#include "endscore.h"
#include <QFont>

EndScore::EndScore(int score)
{
    setPlainText(QString("Final score: ") + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 35));
    setPos(1150 / 2 - boundingRect().width() / 2, 100);
}
