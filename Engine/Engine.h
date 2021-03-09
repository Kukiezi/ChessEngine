#ifndef ENGINE_H
#define ENGINE_H
#include <string>
#include "Game.h"

class Engine
{
std::unique_ptr<Game> game_;


public:
    void startGame(std::string fenString = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");

    void makeMove(std::string move);
    ChessBoard* getChessBoard() const;
    Game* getGame();
private:
    void setGame(std::unique_ptr<Game> game);
};

#endif // ENGINE_H
