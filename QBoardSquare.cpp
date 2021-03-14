#include "QBoardSquare.h"
#include <QGraphicsView>
#include <QGraphicsSceneDragDropEvent>
#include <QGraphicsRectItem>

QBoardSquare::QBoardSquare(Color color, int x, int y, int row, int col)
{
    this->row = row;
    this->col = col;
    this->color = color;
    this->setBrush(color == Color::White ? Qt::white : QColor("#964b00"));
    this->setPos(x, y);
    this->setRect(0, 0, QBoardSquare::rectSize, QBoardSquare::rectSize);
}

void QBoardSquare::setPiece(QPiece* piece)
{
    if (this->piece != NULL) {
        this->piece->getScene()->removeItem(this->piece);
    }
    this->piece = piece;
    this->piece->setPos(this->pos().x(), this->pos().y());
    this->piece->setAnchorPoint(QPoint(this->pos().x(), this->pos().y()));
}

void QBoardSquare::removePiece()
{
    piece = nullptr;
}
