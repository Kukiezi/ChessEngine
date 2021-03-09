#ifndef GAME_H
#define GAME_H
#include <string>
#include <list>
#include "ChessBoard.h"
#include "FenService.h"
#include "Move.h"
#include "MoveValidator.h"


class Game
{
Color player1_ = Color::White;
Color player2_ = Color::Black;

Color* turn_ = &player1_;

std::unique_ptr<ChessBoard> chessBoard_;

public:
    Game(std::string fenString);

    ChessBoard* getChessBoard();
    void setNextTurn();
    void makeMove(std::string moveString);
    std::list<Move*> generateLegalMoves(std::pair<int, int> startingSquare);
    void setChessBoard(std::unique_ptr<ChessBoard> chessBoard);
    void printChessBoard();

private:
    Color getFriendlyPieces();

};

#endif // GAME_H
