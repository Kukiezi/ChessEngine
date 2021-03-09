#include "Game.h"

Game::Game(std::__1::string fenString)
{
    setChessBoard(std::make_unique<ChessBoard>());
    FanService::addPieceToBoardFromFenString(fenString, chessBoard_);
}

ChessBoard* Game::getChessBoard()
{
    return chessBoard_.get();
}

void Game::setNextTurn()
{
    if (*turn_ == player1_) {
        turn_ = &player2_;
        return;
    }

    turn_ = &player1_;
}

void Game::makeMove(std::string moveString)
{
    std::unique_ptr<Move> move = std::make_unique<Move>(moveString);

    if (!MoveValidator::isMoveLegal(getChessBoard(), move, *turn_)) {
        std::cout << "illegal move" << std::endl;
        return;
    }

    auto piece = chessBoard_->boardSquares[move->from.first][move->from.second]->getPiece();

    chessBoard_->boardSquares[move->to.first][move->to.second]->setPiece(piece);
    chessBoard_->boardSquares[move->from.first][move->from.second]->resetPiece();

    piece->setMoved(true);
    setNextTurn();
}

void Game::setChessBoard(std::unique_ptr<ChessBoard> chessBoard)
{
    chessBoard_ = std::move(chessBoard);
}

void Game::printChessBoard()
{
    getChessBoard()->printChessBoard();
}

