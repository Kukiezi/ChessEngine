#pragma once

#include <string>
#include "QChessBoard.h"

class FenReader
{
public:
    void addPiececToBoardRectFromFen(std::string fenString, QChessBoard* board, QGraphicsScene* scene);
    QPiece* getPieceFromFen(char piece, QGraphicsScene* scene);
};

