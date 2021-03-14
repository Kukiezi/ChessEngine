#ifndef GAME_H
#define GAME_H
#include <string>
#include <list>
#include "ChessBoard.h"
#include "FenService.h"
#include "Move.h"
#include "MoveValidator.h"
#include "GameState.h"

class Game
{
std::vector<std::shared_ptr<Move>> listOfMoves;
Color player1_ = Color::White;
Color player2_ = Color::Black;
GameState gameState_ = GameState::NOT_STARTED;
Color* turn_ = &player1_;
std::shared_ptr<ChessBoard> chessBoard_;

public:
    Game(std::string fenString);

    ChessBoard* getChessBoard();
    ChessBoard getChessBoardCopy();
    void setNextTurn();
    bool makeMove(std::shared_ptr<Move> move);
    std::shared_ptr<Move> createMove(std::string moveString);
    std::shared_ptr<Move> createMove(std::pair<int, int> from, std::pair<int, int> to);
    void setChessBoard(std::shared_ptr<ChessBoard> chessBoard);
    void printChessBoard();
    Color getTurn();

private:
    Color getFriendlyPieces();


};

#endif // GAME_H
