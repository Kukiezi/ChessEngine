#include "QGame.h"
#include <QGraphicsScene>

QGame::QGame(std::__1::string fen)
{
    this->startingFen_ = fen;
}

void QGame::startGame(QGraphicsScene* scene)
{
    this->board = new QChessBoard();
    engine = std::make_unique<Engine>();
    engine->startGame();
    this->initializeBoard(scene, engine->getChessBoard());
}

void QGame::initializeBoard(QGraphicsScene* scene, ChessBoard* chessBoard)
{
    initializePieces(scene, chessBoard);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            scene->addItem(board->boardSquares[i][j]);
            if (board->boardSquares[i][j]->piece != NULL) {
                scene->addItem(board->boardSquares[i][j]->piece);
            }
        }
    }
}

void QGame::initializePieces(QGraphicsScene *scene, ChessBoard* chessBoard)
{
    for (int x = 0; x < 8; x++) {
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



