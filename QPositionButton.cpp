#include "QPositionButton.h"
#include <QDebug>
#include "QGame.h"

QPositionButton::QPositionButton(QPositionInput* input): QGraphicsRectItem()
{
    this->input = input;
    this->setBrush(QColor("#3A3B3C"));
    this->setPos(0, 0);
    this->setRect(0, 150, 100, 50);
    std::pair<int, int> pos = std::make_pair(5, 150);
    backLabel = std::unique_ptr<QSavedGameText>(new QSavedGameText("Start Game", pos));
}

void QPositionButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    extern QGame * game;
    extern QGraphicsScene* scene;
    extern Engine * engine;
    game->startGame(GameType::POSITION, input->text().toUtf8().constData());
}
