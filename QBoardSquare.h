#pragma once

#include <QGraphicsRectItem>
#include "UI/Pieces/QPieces.h"

class QBoardSquare: public QGraphicsRectItem
{
public:
    bool dragged_;
    Color color;
    QPiece* piece = NULL;
    static const int rectSize = 100;
    int row;
    int col;
    QBoardSquare(Color color, int x, int y, int row, int col);
    QEngine& engine = QEngine::getInstance();
    std::pair<int, int> from;
    std::pair<int, int> to;

    void setPiece(QPiece* piece);
    void removePiece();
};

