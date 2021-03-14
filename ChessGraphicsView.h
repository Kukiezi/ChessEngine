#ifndef CHESSGRAPHICSVIEW_H
#define CHESSGRAPHICSVIEW_H
#include <QGraphicsView>


class ChessGraphicsView : public QGraphicsView
{
public:
    ChessGraphicsView(QGraphicsScene* scene);
    void scrollContenstsBy(int, int);
};

#endif // CHESSGRAPHICSVIEW_H
