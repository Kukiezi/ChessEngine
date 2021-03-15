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

QPiece *QBoardSquare::getPiece()
{
    return piece;
}

void QBoardSquare::setColor(Color color)
{
    if (color == Color::White) {
        this->setBrush(Qt::white);
    } else if (color == Color::Brown) {
        this->setBrush(QColor("#964b00"));
    } else if (color == Color::MOVE_FROM){
        this->setBrush(QColor("#FFFACD"));
    } else if (color == Color::MOVE_TO){
        this->setBrush(QColor("#FFFF99"));
    }
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
