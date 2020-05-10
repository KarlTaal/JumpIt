#include "replaybutton.h"
#include <QDebug>
#include "Game.h"
#include <QGraphicsProxyWidget>
extern Game* game;

ReplayButton::ReplayButton()
{
    setGeometry(QRect(QPoint(250, 400),QSize(200, 50)));
    setText("Replay");
    QObject::connect(this, SIGNAL(clicked()), this, SLOT(replay()));
}

void ReplayButton::replay()
{
  //new player
  Player* p = new Player();
  game->player = p;
  game->scene->addItem(p);
  p->setPos(400, 500);
  p->setFlag(QGraphicsItem::ItemIsFocusable);
  p->setFocus();

  //new score
  Score* s = new Score();
  game->scene->addItem(s);
  game->score = s;

  game->scene->removeItem(graphicsProxyWidget());
  game->scene->removeItem(game->endscore);
}
