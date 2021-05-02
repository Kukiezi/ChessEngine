#include "QChessBackButton.h"
extern QGame * game;

QChessBackButton::QChessBackButton()
{
    this->setBrush(QColor("#E4E6EB"));
    this->setPos(825, 700);
    this->setRect(0, 0, 100, 50);
}

void QChessBackButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    game->MakeMoveBackward();
}
