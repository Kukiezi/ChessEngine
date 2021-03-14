#include "Game.h"

Game::Game(std::__1::string fenString)
{
    setChessBoard(std::make_unique<ChessBoard>());
    FanService::addPieceToBoardFromFenString(fenString, chessBoard_);
    gameState_ = GameState::IN_PROGRESS;
}

ChessBoard* Game::getChessBoard()
{
    return chessBoard_.get();
}

ChessBoard Game::getChessBoardCopy()
{
    return *chessBoard_;
}

void Game::setNextTurn()
{
    if (*turn_ == player1_) {
        turn_ = &player2_;
        return;
    }

    turn_ = &player1_;
}

bool Game::makeMove(std::shared_ptr<Move> move)
{
    if (gameState_ == GameState::FINISHED) {
        std::cout << "Game HAS FINISHED" << std::endl;
        return false;
    }
    if (!MoveValidator::isMoveLegal(getChessBoard(), move, *turn_)) {
        return false;
    }

    auto piece = chessBoard_->boardSquares[move->from.first][move->from.second]->getPiece();

    chessBoard_->boardSquares[move->to.first][move->to.second]->setPiece(piece);
    chessBoard_->boardSquares[move->from.first][move->from.second]->resetPiece();

    piece->setMoved(true);
    setNextTurn();

    listOfMoves.push_back(move);
    if (MoveValidator::isGameOver(getChessBoard(), *turn_)) {
        gameState_ = GameState::FINISHED;
    }
    return true;
}

std::shared_ptr<Move> Game::createMove(std::string moveString)
{
    std::shared_ptr<Move> move = std::make_shared<Move>(moveString);
    return move;
}

std::shared_ptr<Move> Game::createMove(std::pair<int, int> from, std::pair<int, int> to)
{
    std::shared_ptr<Move> move = std::make_shared<Move>(from, to);
    return move;
}

void Game::setChessBoard(std::shared_ptr<ChessBoard> chessBoard)
{
    chessBoard_ = chessBoard;
}

void Game::printChessBoard()
{
    getChessBoard()->printChessBoard();
}

Color Game::getTurn()
{
    return *turn_;
}

