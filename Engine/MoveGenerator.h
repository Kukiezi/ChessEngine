#ifndef MOVEGENERATOR_H
#define MOVEGENERATOR_H
#include <list>
#include "Move.h"

class MoveGenerator
{
public:
    static std::list<Move*> generateLegalMoves(ChessBoard* chessBoard, std::pair<int, int> startingSquare, Color friendlyPieceColor);
    static std::list<Move*> generateAllLegalMoves(ChessBoard* chessBoard, Color friendlyPieceColor);
    static bool isKingInCheck(ChessBoard* chessBoard, Color friendlyPieceColor);
    static bool performMove(ChessBoard* chessBoard, Move* move);
    static void getOpponentsAllAttackedSquares(ChessBoard* chessBoard, Color friendlyPieceColor, std::list<BoardSquare*>& attackedSquares);
private:
    static void generateLegalMovesForSlidingPieces(ChessBoard* chessBoard, std::pair<int, int> startingSquare, std::shared_ptr<Piece> piece, Color friendlyPieceColor, std::list<Move*>& legalMoves);
    static void generateLegalMovesForPawn(ChessBoard* chessBoard, std::pair<int, int> startingSquare, std::shared_ptr<Piece> piece, Color friendlyPieceColor, std::list<Move*>& legalMoves);
    static void generateLegalMovesForKing(ChessBoard* chessBoard, std::pair<int, int> startingSquare, std::shared_ptr<Piece> piece, Color friendlyPieceColor, std::list<Move*>& legalMoves);
    static void generateLegalMovesForKnight(ChessBoard* chessBoard, std::pair<int, int> startingSquare, std::shared_ptr<Piece> piece, Color friendlyPieceColor, std::list<Move*>& legalMoves);
    static void generateForwardMovesForPawn(ChessBoard* chessBoard, std::pair<int, int> startingSquare, std::shared_ptr<Piece> piece, Color friendlyPieceColor, std::list<Move*>& legalMoves);
    static void generateAttackingMovesForPawn(ChessBoard* chessBoard, std::pair<int, int> startingSquare, std::shared_ptr<Piece> piece, Color friendlyPieceColor, std::list<Move*>& legalMoves);
    static void printLegalMoves(std::list<Move*>& legalMoves);
    static bool isSquareUnderAttack(int row, int col, std::list<BoardSquare*> attackedSquares);
    static void generateLegalCastleMovesForKing(ChessBoard* chessBoard, std::pair<int, int> startingSquare, std::shared_ptr<Piece> piece, Color friendlyPieceColor, std::list<Move*>& legalMoves);
};

#endif // MOVEGENERATOR_H
