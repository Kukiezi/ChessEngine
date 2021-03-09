#ifndef QGAME_H
#define QGAME_H
#include "UI/Pieces/QPieces.h"
#include "QChessBoard.h"
#include "Fen.h"
#include "Engine/Engine.h"
#include "Engine/Pieces/Pieces.h"

class QGame
{
    QChessBoard* board;
    std::string startingFen_;
public:
    std::unique_ptr<Engine> engine;
    QGame(std::string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");

    void startGame(QGraphicsScene* scene);

private:
    void initializeBoard(QGraphicsScene* scene, ChessBoard* chessBoard);
    void initializePieces(QGraphicsScene* scene, ChessBoard* chessBoard);
    QPiece *getPieceFromEngine(QGraphicsScene* scene, std::shared_ptr<Piece> piece);
};


#endif // QGAME_H
