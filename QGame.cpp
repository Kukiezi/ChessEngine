#include "QGame.h"
#include <QGraphicsScene>
#include <ChessGraphicsView.h>

extern QGraphicsScene * scene;
extern ChessGraphicsView* view;
extern Engine * engine;

QGame::QGame(std::__1::string fen)
{
    this->startingFen_ = fen;
}

Turn* QGame::getTurn()
{
    return turn_;
}

void QGame::startGame(GameType gameType, std::string fen)
{
    this->gameType_ = gameType;
    this->board = new QChessBoard();
    engine->startGame(fen, gameType);
    this->initializeBoard(engine->getChessBoard());
    auto startingTurn = engine->getTurn();
    turn_ = new Turn();
    turn_->setTurn(startingTurn);
    chessMenu = new QChessMenu();
    scene->addItem(turn_);
}

void QGame::getSavedGamesScreen()
{
    auto backButton = new QBackButton;
    scene->addItem(backButton);
    scene->addItem(backButton->backLabel.get());
    std::shared_ptr<QSavedGames> savedGames(new QSavedGames());
    for (auto game : savedGames->savedGames) {
        scene->addItem(game);
        scene->addItem(game->gameLabel.get());
    }

}

void QGame::startReplay(std::string path)
{
    this->gameType_ = GameType::REPLAY;
    scene->clear();
    engine = new Engine();
    this->board = new QChessBoard();
    engine->startReplay(path);
    this->initializeBoard(engine->getChessBoard());
    chessMenu = new QChessMenu();
}

void QGame::resetSquareColors()
{
    this->board->resetSquareColors();
}

QChessBoard* QGame::getChessBoard()
{
    return board;
}

void QGame::MakeMoveBackward()
{
    auto move = engine->makeMoveBackward();
    if (move == NULL) {
        return;
    }
    QMove* qMove = new QMove();
    qMove->from = this->getChessBoard()->boardSquares[move->from.first][move->from.second];
    qMove->to = this->getChessBoard()->boardSquares[move->to.first][move->to.second];
    auto pieceToMove = this->getChessBoard()->boardSquares[move->from.first][move->from.second]->getPiece();
    pieceToMove->setZValue(10);
    qMove->to->setPiece(pieceToMove);
    qMove->from->removePiece();
    resetSquareColors();

    delete qMove;
}

void QGame::MakeMoveForward()
{
    auto move = engine->makeMoveForward();
    if (move == NULL) {
        return;
    }
    QMove* qMove = new QMove();
    qMove->from = this->getChessBoard()->boardSquares[move->from.first][move->from.second];
    qMove->to = this->getChessBoard()->boardSquares[move->to.first][move->to.second];
    auto pieceToMove = this->getChessBoard()->boardSquares[move->from.first][move->from.second]->getPiece();
    pieceToMove->setZValue(10);
    qMove->to->setPiece(pieceToMove);
    qMove->from->removePiece();
    resetSquareColors();
    qMove->from->setColor(Color::MOVE_FROM);
    qMove->to->setColor(Color::MOVE_TO);

    if (pieceToMove->getName() == "King" && move->isCastleMove) {
        QMove* qMove = new QMove();
        qMove->from = this->getChessBoard()->boardSquares[move->castleFrom.first][move->castleFrom.second];
        qMove->to = this->getChessBoard()->boardSquares[move->castleTo.first][move->castleTo.second];
        auto pieceToMove = this->getChessBoard()->boardSquares[move->castleFrom.first][move->castleFrom.second]->getPiece();
        pieceToMove->setZValue(10);
        qMove->to->setPiece(pieceToMove);
        qMove->from->removePiece();
    }
    delete qMove;
}

void QGame::clearMemory()
{
    delete this->board;
    delete this->chessMenu;
}

GameType QGame::getGameType()
{
    return gameType_;
}

void QGame::getStartFromPositionScreen()
{
    QPositionInput* input = new QPositionInput();
    QPositionButton* button = new QPositionButton(input);

    auto backButton = new QBackButton;
    scene->addItem(backButton);
    scene->addItem(backButton->backLabel.get());
    scene->addWidget(input);
    scene->addItem(button);
    scene->addItem(button->backLabel.get());
}


void QGame::initializeBoard(ChessBoard* chessBoard)
{
    initializePieces(chessBoard);

    for (int i = 7; i >= 0; i--) {
        for (int j = 0; j < 8; j++) {
            scene->addItem(board->boardSquares[i][j]);
            if (board->boardSquares[i][j]->piece != NULL) {
                scene->addItem(board->boardSquares[i][j]->piece);
            }
        }
    }

    auto backButton = new QBackButton;
    scene->addItem(backButton);
    scene->addItem(backButton->backLabel.get());
    scene->addItem(new QChessMenu());

    if (gameType_ == GameType::REPLAY) {
        auto chessBackButton = new QChessBackButton();
        auto chessForwardButton = new QChessForwardButton();
        scene->addItem(chessBackButton);
        scene->addItem(chessBackButton->label.get());
        scene->addItem(chessForwardButton);
        scene->addItem(chessForwardButton->label.get());
    }

}

void QGame::initializePieces(ChessBoard* chessBoard)
{
    for (int x = 7; x >= 0; x--) {
        for (int y = 0; y < 8; y++) {
            QPiece* pieceToAdd = getPieceFromEngine(chessBoard->boardSquares[x][y]->getPiece());
            if (pieceToAdd != NULL) {
                board->boardSquares[x][y]->setPiece(getPieceFromEngine(chessBoard->boardSquares[x][y]->getPiece()));
            }
        }
    }
}

QPiece *QGame::getPieceFromEngine(std::shared_ptr<Piece> piece)
{
    if (piece == nullptr) {
        return NULL;
    }

    if (piece->getShortName() == "Q") {
        return new QQueen(piece->getColor());
    } else if (piece->getShortName() == "R") {
        return new QRook(piece->getColor());
    } else if (piece->getShortName() == "B") {
        return new QBishop(piece->getColor());
    } else if (piece->getShortName() == "P") {
        return new QPawn(piece->getColor());
    } else if (piece->getShortName() == "N") {
        return new QKnight(piece->getColor());
    } else if (piece->getShortName() == "K") {
        return new QKing(piece->getColor());
    }
}



