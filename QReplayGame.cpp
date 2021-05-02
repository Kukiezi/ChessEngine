#include "QReplayGame.h"

extern Engine * engine;

void QReplayGame::MakeMoveBackward()
{
    auto move = engine->makeMoveBackward();
    if (move == NULL) {
        return;
    }
    QMove* qMove = new QMove();
    qMove->from = this->getChessBoard()->boardSquares[move->from.first][move->from.second];
    qMove->to = this->getChessBoard()->boardSquares[move->to.first][move->to.second];
    auto pieceToMove = this->getChessBoard()->boardSquares[move->from.first][move->from.second]->getPiece();
    qMove->to->setPiece(pieceToMove);
    qMove->from->removePiece();
    delete qMove;
}

void QReplayGame::MakeMoveForward()
{
    auto move = engine->makeMoveForward();
    if (move == NULL) {
        return;
    }
    QMove* qMove = new QMove();
    qMove->from = this->getChessBoard()->boardSquares[move->from.first][move->from.second];
    qMove->to = this->getChessBoard()->boardSquares[move->to.first][move->to.second];
    auto pieceToMove = this->getChessBoard()->boardSquares[move->from.first][move->from.second]->getPiece();
    qMove->to->setPiece(pieceToMove);
    qMove->from->removePiece();
    delete qMove;
}
