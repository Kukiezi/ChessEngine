#pragma once

#include "QBoardSquare.h"
#include "UI/Pieces/QPieces.h"

class QChessBoard
{
    std::vector<std::vector<QBoardSquare*>> boardSquares_;
public:
    std::vector<std::vector<QBoardSquare*>> & boardSquares() {return boardSquares_;}
    QChessBoard();
    void resetSquareColors();

private:
    Color getNextColor(Color currentColor, int currentColumn);
};

