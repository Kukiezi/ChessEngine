#include "ChessGraphicsView.h"

ChessGraphicsView::ChessGraphicsView(QGraphicsScene* scene) : QGraphicsView(scene)
{
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);

}

void ChessGraphicsView::scrollContenstsBy(int, int)
{

}
