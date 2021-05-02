#ifndef REPLAYGAME_H
#define REPLAYGAME_H
#include "Game.h"

class ReplayGame : public Game
{
public:
    ReplayGame(std::list<std::string> listOfGameMoves, std::string fenString);
    int currentMoveIndex = 0;

    std::vector<std::shared_ptr<Move>> listOfGameMoves;
    std::shared_ptr<Move> makeMoveBackward();
    std::shared_ptr<Move> makeMoveForward();
};

#endif // REPLAYGAME_H
