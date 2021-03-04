#ifndef BOARDRECT_H
#define BOARDRECT_H
#include <QGraphicsRectItem>
#include "Color.cpp"
#include "Pieces.h"

class BoardRect: public QGraphicsRectItem
{
public:
    Color color;
    Piece* piece;

    static const int rectSize = 100;

    BoardRect(Color color, int x, int y);

    void setPiece(Piece* piece);
};


#endif // BOARDRECT_H
