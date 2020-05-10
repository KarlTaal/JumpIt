#include "endscore.h"
#include <QFont>


EndScore::EndScore(int score)
{
    setPlainText(QString("Final score: ") + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 35));
    setPos(450, 200);
}
