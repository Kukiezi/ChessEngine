#include "MoveValidator.h"

bool MoveValidator::isMoveLegal(ChessBoard* chessBoard, std::shared_ptr<Move> move, Color friendlyPieceColor)
{
    if (!move->isMoveCoordinatesValid()) {
        std::cout << "illegal coordinates" << std::endl;
        return false;
    }

    auto piece = chessBoard->boardSquares[move->from.first][move->from.second]->getPiece();

    if (!MoveValidator::isPieceOnStartingSquareFriendly(piece, friendlyPieceColor)) {
        std::cout << "not friendly piece on starting square" << std::endl;
        return false;
    }

    auto legalMoves = MoveValidator::getAllLegalMoves(chessBoard, friendlyPieceColor);

    for (auto legalMove : legalMoves) {
        if (move->isEqual(legalMove)) {
            return true;
        }
    }
    std::cout << "not a legal move" << std::endl;
    return false;
}

bool MoveValidator::isGameOver(ChessBoard *chessBoard, Color friendlyPieceColor)
{
    auto legalMoves = MoveValidator::getAllLegalMoves(chessBoard, friendlyPieceColor);

    if (legalMoves.size() == 0) {
        auto opponentsColor = friendlyPieceColor == Color::White ? "Black layer" : "White player!";
        std::cout << "GAME HAS ENDED" << std::endl;
        std::cout << "AND THE WINNER IS: " << opponentsColor << std::endl;
        return true;
    }
    return false;
}

std::list<Move*> MoveValidator::getAllLegalMoves(ChessBoard* chessBoard, Color friendlyPieceColor)
{
    auto legalMoves = MoveGenerator::generateAllLegalMoves(chessBoard, friendlyPieceColor);
    auto legalMovesAfterKingCheck = MoveValidator::performTheLegalMovesAndEraseThoseThatCauseCheckOnFriendlyKing(legalMoves, chessBoard, friendlyPieceColor);

    return legalMovesAfterKingCheck;
}

std::list<Move*> MoveValidator::performTheLegalMovesAndEraseThoseThatCauseCheckOnFriendlyKing(std::list<Move*> legalMoves, ChessBoard* chessBoard, Color friendlyPieceColor)
{
    for (std::list<Move*>::iterator it = legalMoves.begin(); it != legalMoves.end(); ++it){
        std::pair<int, int> from = std::make_pair((*it)->from.first, (*it)->from.second);
        std::pair<int, int> to = std::make_pair((*it)->to.first, (*it)->to.second);
        auto pieceToRevert = chessBoard->boardSquares[to.first][to.second]->getPiece();
        bool shouldRevertDidPieceMove = MoveGenerator::performMove(chessBoard, (*it));
        if (MoveGenerator::isKingInCheck(chessBoard, friendlyPieceColor)) {
            legalMoves.erase(it);
        }
        auto movedPiece = chessBoard->boardSquares[to.first][to.second]->getPiece();
        chessBoard->boardSquares[from.first][from.second]->setPiece(movedPiece);
        if (shouldRevertDidPieceMove)
        {
            chessBoard->boardSquares[from.first][from.second]->getPiece()->setMoved(false);
        }
        if (pieceToRevert == nullptr) {
            chessBoard->boardSquares[to.first][to.second]->resetPiece();
        } else {
            chessBoard->boardSquares[to.first][to.second]->setPiece(pieceToRevert);
        }
    }

    return legalMoves;
}

bool MoveValidator::isPieceOnStartingSquareFriendly(std::shared_ptr<Piece> piece, Color friendlyPieceColor)
{
    if (piece == nullptr || piece->getColor() != friendlyPieceColor) {
        return false;
    }
    return true;
}

