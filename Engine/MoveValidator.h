#ifndef MOVEVALIDATOR_H
#define MOVEVALIDATOR_H
#include "ChessBoard.h"
#include "Move.h"
#include "MoveGenerator.h"

class MoveValidator
{
public:
    static bool isMoveLegal(ChessBoard* chessBoard, std::unique_ptr<Move>& move, Color friendlyPieceColor);
private:
    static bool isPieceOnStartingSquareFriendly(std::shared_ptr<Piece> piece, Color friendlyPieceColor);
};

#endif // MOVEVALIDATOR_H
