#include "replaybutton.h"
#include "Game.h"
#include <QGraphicsProxyWidget>

#include <vector>

extern Game* game;

ReplayButton::ReplayButton()
{
    setGeometry(QRect(QPoint(1150 / 2 - 100, 200),QSize(200, 50)));
    setText("Play again");
    QObject::connect(this, SIGNAL(clicked()), this, SLOT(replay()));
}

void ReplayButton::replay()
{
  //new player
  Player* p = new Player();
  game->player = p;
  game->scene->addItem(p);
  p->setPos(400, 410);
  p->setFlag(QGraphicsItem::ItemIsFocusable);
  p->setFocus();

  //new score
  Score* s = new Score();
  game->scene->addItem(s);
  game->score = s;

  EndScore* ptr1 = game->endscore;

  game->scene->removeItem(graphicsProxyWidget());
  game->scene->removeItem(game->endscore);

  delete ptr1;
  deleteLater();
}
