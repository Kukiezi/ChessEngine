#include "QChessForwardButton.h"

extern QGame * game;

QChessForwardButton::QChessForwardButton()
{
    this->setBrush(QColor("#E4E6EB"));
    this->setPos(935, 700);
    this->setRect(0, 0, 100, 50);
}

void QChessForwardButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    game->MakeMoveForward();
}
