#ifndef ENGINE_H
#define ENGINE_H
#include <string>
#include "Game.h"

class Engine
{
std::unique_ptr<Game> game_;


public:
    void startGame(std::string fenString = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");

    bool makeMove(std::string move);
    bool makeMove(std::pair<int, int> from, std::pair<int, int> to);
    std::shared_ptr<Move> getAIMove();
    Color getTurn();
    ChessBoard* getChessBoard() const;
    Game* getGame();
private:
    void setGame(std::unique_ptr<Game> game);
};

#endif // ENGINE_H
