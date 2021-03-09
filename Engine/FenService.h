#ifndef FENSERVICE_H
#define FENSERVICE_H
#include <string>
#include "ChessBoard.h"
#include "Pieces/Pieces.h"

class FanService
{
public:
    static void addPieceToBoardFromFenString(std::string fenString, std::unique_ptr<ChessBoard>& board);
    static std::unique_ptr<Piece> getPieceFromFen(char piece);
};

#endif // FENSERVICE_H
