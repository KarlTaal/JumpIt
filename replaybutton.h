#ifndef REPLAYBUTTON_H
#define REPLAYBUTTON_H

#include <QPushButton>

class ReplayButton:public QPushButton{
    Q_OBJECT
public:
    ReplayButton();

public slots:
    void replay();
};

#endif // REPLAYBUTTON_H
