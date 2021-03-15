#pragma once

#include "UI/Pieces/QPieces.h"
#include "QChessBoard.h"
#include "Fen.h"
#include "Engine/Pieces/Pieces.h"
#include "QEngine.h"
#include "Engine/Engine.h"
#include "Turn.h"
#include "QChessMenu.h"

class QGame
{
    QChessMenu* chessMenu;
    QChessBoard* board;
    std::string startingFen_;
    std::shared_ptr<Turn> turn_;
public:
    QEngine& engine = QEngine::getInstance();
    QGame(std::string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
    std::shared_ptr<Turn> getTurn();
    void startGame(QGraphicsScene* scene);
    void resetSquareColors();
    QChessBoard* getChessBoard();

private:
    void initializeBoard(QGraphicsScene* scene, ChessBoard* chessBoard);
    void initializePieces(QGraphicsScene* scene, ChessBoard* chessBoard);
    QPiece *getPieceFromEngine(QGraphicsScene* scene, std::shared_ptr<Piece> piece);
};
