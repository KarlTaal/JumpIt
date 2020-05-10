#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "Obstacle.h"
#include "Score.h"
#include <QTimer>
#include "endscore.h"

class Game: public QGraphicsView{
public:
    Game (QWidget* parent=0);

    QGraphicsScene* scene;
    Player* player;
    Score* score;
    bool inGame;
    QTimer* timer;
    EndScore* endscore;

};

#endif // GAME_H
