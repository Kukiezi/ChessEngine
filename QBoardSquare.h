#ifndef QBOARDSQUARE_H
#define QBOARDSQUARE_H
#include <QGraphicsRectItem>
#include "UI/Pieces/QPieces.h"

class QBoardSquare: public QGraphicsRectItem
{
public:
    Color color;
    QPiece* piece = NULL;
    static const int rectSize = 100;

    QBoardSquare(Color color, int x, int y);

    void setPiece(QPiece* piece);
};


#endif // QBOARDSQUARE_H
