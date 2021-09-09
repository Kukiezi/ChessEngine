#include "QChessBackButton.h"
extern QGame * game;

QChessBackButton::QChessBackButton()
{
    this->setBrush(QColor("#E4E6EB"));
    this->setPos(825, 700);
    this->setRect(0, 0, 100, 50);
    std::pair<int, int> pos = std::make_pair(850, 700);
    label(std::unique_ptr<QSavedGameText>(new QSavedGameText("BACK", pos, true)));
}

void QChessBackButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    game->MakeMoveBackward();
}
