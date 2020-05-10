#include "Game.h"
#include <QBrush>
#include <QImage>
#include <QMediaPlaylist>
#include <QMediaPlayer>


Game::Game(QWidget *parent)
{
    int winW = 1150;
    int winH = 540;
    //Create a scene
    scene = new QGraphicsScene;
    scene->setSceneRect(0,0,winW, winH);
    QImage bc = QImage(":/images/background.png");

    scene->setBackgroundBrush(QBrush(bc));

    //Create an item to put into the scene
    player = new Player();

    //add item to the scene
    scene->addItem(player);

    //make rect focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // add a view
    QGraphicsView* view = new QGraphicsView();
    view->setScene(scene);

    view->setFixedSize(winW, winH);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    score = new Score();
    scene->addItem(score);

    player->setPos(400, 410);

    QMediaPlaylist* playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/sounds/music.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    QMediaPlayer* music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->play();

    view->show();

}
