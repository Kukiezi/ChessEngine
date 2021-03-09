#include "MoveValidator.h"

bool MoveValidator::isMoveLegal(ChessBoard *chessBoard, std::unique_ptr<Move>& move, Color friendlyPieceColor)
{
    if (!move->isMoveCoordinatesValid()) {
        return false;
    }

    auto piece = chessBoard->boardSquares[move->from.first][move->from.second]->getPiece();

    if (!MoveValidator::isPieceOnStartingSquareFriendly(piece, friendlyPieceColor)) {
        return false;
    }

    auto legalMoves = MoveGenerator::generateLegalMoves(chessBoard, std::make_pair(move->from.first, move->from.second), friendlyPieceColor);


    for (auto legalMove : legalMoves) {
        if (move->isEqual(legalMove)) {
            return true;
        }
    }

    return false;
}

bool MoveValidator::isPieceOnStartingSquareFriendly(std::shared_ptr<Piece> piece, Color friendlyPieceColor)
{
    if (piece == nullptr || piece->getColor() != friendlyPieceColor) {
        return false;
    }
    return true;
}

