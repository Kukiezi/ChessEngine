#pragma once

#include "QBoardSquare.h"
#include "UI/Pieces/QPieces.h"

class QChessBoard
{
public:
    std::vector<std::vector<QBoardSquare*>> boardSquares;
    QChessBoard();

private:
    Color getNextColor(Color currentColor, int currentColumn);
};

