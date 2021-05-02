#ifndef GAME_H
#define GAME_H
#include <string>
#include <list>
#include <vector>
#include "ChessBoard.h"
#include "FenService.h"
#include "Move.h"
#include "MoveValidator.h"
#include "GameState.h"
#include <iostream>
#include <fstream>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QFileInfo>
#include <QDir>
#include "GameType.h"

class Game
{
std::vector<std::shared_ptr<Move>> listOfMoves;
std::list<std::string> listOfMovesInPGN;
Color player1_ = Color::White;
Color player2_ = Color::Black;
GameState gameState_ = GameState::NOT_STARTED;
Color* turn_ = &player1_;
std::shared_ptr<ChessBoard> chessBoard_;
public:
    GameType gameType;
    std::list<BoardSquare*> attackedSquares;
    Game(std::string fenString, GameType gameType);

    ChessBoard* getChessBoard();
    ChessBoard getChessBoardCopy();
    void setNextTurn();
    std::shared_ptr<Move> getLastCastleMove();
    bool makeMove(std::shared_ptr<Move> move);
    bool makeMoveWithoutLegalChecks(std::shared_ptr<Move> move);
    std::shared_ptr<Move> getAIMove();
    std::shared_ptr<Move> createMove(std::string moveString);
    std::shared_ptr<Move> createMove(std::pair<int, int> from, std::pair<int, int> to);
    void setChessBoard(std::shared_ptr<ChessBoard> chessBoard);
    void printChessBoard();
    Color getTurn();
    std::unique_ptr<Game> getGame();
    bool exportGameToFile();

private:
    Color getFriendlyPieces();


};

#endif // GAME_H
