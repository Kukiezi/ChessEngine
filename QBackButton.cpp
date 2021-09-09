#include "QBackButton.h"
#include "boardwindow.h"

QBackButton::QBackButton()
{
    this->setBrush(QColor("#3A3B3C"));
    this->setPos(0, 0);
    this->setRect(0, 0, 100, 50);
    std::pair<int, int> pos = std::make_pair(25, 0);
    backLabel(std::unique_ptr<QSavedGameText>(new QSavedGameText("Back", pos)));
}

void QBackButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    extern QGraphicsScene* scene;
    extern QGame* game;
    extern BoardWindow* w;

    scene->clear();
    w->setupUi();
}
