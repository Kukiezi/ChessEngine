#include "QSavedGame.h"
#include <QGraphicsView>
#include "QGame.h"
#include <QPainter>
extern QGame * game;

QSavedGame::QSavedGame(std::map<std::string, std::string> savedGame, std::pair<int, int> pos)
{
    this->name(savedGame.at("name"));
    this->path(savedGame.at("path"));
    this->setBrush(QColor("#3A3B3C"));
    this->setPos(pos.first, pos.second);
    this->setRect(0, 0, 200, 100);
    gameLabel(std::unique_ptr<QSavedGameText>(new QSavedGameText(this->name(), pos)));
}

void QSavedGame::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    game->startReplay(this->path());
}
