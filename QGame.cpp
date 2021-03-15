#include "QGame.h"
#include <QGraphicsScene>

QGame::QGame(std::__1::string fen)
{
    this->startingFen_ = fen;
}

std::shared_ptr<Turn> QGame::getTurn()
{
    return turn_;
}

void QGame::startGame(QGraphicsScene* scene)
{
    this->board = new QChessBoard();
    engine.getEngine()->startGame();
    this->initializeBoard(scene, engine.getEngine()->getChessBoard());
    turn_ = std::shared_ptr<Turn>(new Turn());
    chessMenu = new QChessMenu();
    scene->addItem(turn_.get());
}

void QGame::resetSquareColors()
{
    this->board->resetSquareColors();
}

QChessBoard* QGame::getChessBoard()
{
    return board;
}

void QGame::initializeBoard(QGraphicsScene* scene, ChessBoard* chessBoard)
{
    initializePieces(scene, chessBoard);

    for (int i = 7; i >= 0; i--) {
        for (int j = 0; j < 8; j++) {
            scene->addItem(board->boardSquares[i][j]);
            if (board->boardSquares[i][j]->piece != NULL) {
                scene->addItem(board->boardSquares[i][j]->piece);
            }
        }
    }
    scene->addItem(new QChessMenu());
}

void QGame::initializePieces(QGraphicsScene *scene, ChessBoard* chessBoard)
{
    for (int x = 7; x >= 0; x--) {
        for (int y = 0; y < 8; y++) {
            QPiece* pieceToAdd = getPieceFromEngine(scene, chessBoard->boardSquares[x][y]->getPiece());
            if (pieceToAdd != NULL) {
                board->boardSquares[x][y]->setPiece(getPieceFromEngine(scene, chessBoard->boardSquares[x][y]->getPiece()));
            }
        }
    }
}

QPiece *QGame::getPieceFromEngine(QGraphicsScene* scene, std::shared_ptr<Piece> piece)
{
    if (piece == nullptr) {
        return NULL;
    }

    if (piece->getShortName() == "Q") {
        return new QQueen(scene, piece->getColor());
    } else if (piece->getShortName() == "R") {
        return new QRook(scene, piece->getColor());
    } else if (piece->getShortName() == "B") {
        return new QBishop(scene, piece->getColor());
    } else if (piece->getShortName() == "P") {
        return new QPawn(scene, piece->getColor());
    } else if (piece->getShortName() == "N") {
        return new QKnight(scene, piece->getColor());
    } else if (piece->getShortName() == "K") {
        return new QKing(scene, piece->getColor());
    }
}



