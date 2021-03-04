#include "BoardRect.h"
#include <QGraphicsView>

BoardRect::BoardRect(Color color, int x, int y)
{
    this->color = color;
    this->setBrush(color == Color::White ? Qt::white : QColor("#964b00"));

    this->setRect(x, y, BoardRect::rectSize, BoardRect::rectSize);
    this->setPiece(new Queen(Color::White));
    this->piece->setPos(x, y);
}

void BoardRect::setPiece(Piece* piece)
{
    this->piece = piece;

}
