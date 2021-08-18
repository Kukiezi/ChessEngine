#ifndef REPLAYGAME_H
#define REPLAYGAME_H
#include "Game.h"

//!  A ReplayGame class.
/*!
  This class inherits from Game and provides extra functionality to run replays
*/
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
