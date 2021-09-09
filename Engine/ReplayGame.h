#ifndef REPLAYGAME_H
#define REPLAYGAME_H
#include "Game.h"

//!  A ReplayGame class.
/*!
  This class inherits from Game and provides extra functionality to run replays
*/
class ReplayGame : public Game
{
    int currentMoveIndex_ = 0;
public:
    int currentMoveIndex() & {return currentMoveIndex_;}
    void currentMoveIndex(int currentMoveIndex) {
        if (currentMoveIndex < 0) {
            throw std::invalid_argument("currentMoveIndex must be bigger than 0");
        }
        currentMoveIndex_ = currentMoveIndex;
    }
    ReplayGame(std::list<std::string> listOfGameMoves, std::string fenString);

    std::vector<std::shared_ptr<Move>> listOfGameMoves;
    std::shared_ptr<Move> makeMoveBackward();
    std::shared_ptr<Move> makeMoveForward();
};

#endif // REPLAYGAME_H
