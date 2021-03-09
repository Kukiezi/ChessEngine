#ifndef FEN_H
#define FEN_H
#include <string>
#include "QChessBoard.h"

class FenReader
{
public:
    void addPiececToBoardRectFromFen(std::string fenString, QChessBoard* board, QGraphicsScene* scene);
    QPiece* getPieceFromFen(char piece, QGraphicsScene* scene);
};

#endif // FEN_H
