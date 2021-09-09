#include "QChessForwardButton.h"

extern QGame * game;

QChessForwardButton::QChessForwardButton()
{
    this->setBrush(QColor("#E4E6EB"));
    this->setPos(935, 700);
    this->setRect(0, 0, 100, 50);
    std::pair<int, int> pos = std::make_pair(945, 700);
    label(std::unique_ptr<QSavedGameText>(new QSavedGameText("FORWARD", pos, true)));
}

void QChessForwardButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    game->MakeMoveForward();
}
