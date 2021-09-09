#include "ReplayGame.h"

ReplayGame::ReplayGame(std::list<std::string> listOfGameMoves, std::string fenString) : Game(fenString, GameType::REPLAY)
{
    for (auto move : listOfGameMoves) {
        this->listOfGameMoves.push_back(createMove(move));
    }
}

std::shared_ptr<Move> ReplayGame::makeMoveBackward()
{
    if (currentMoveIndex() < 1) {
        return NULL;
    }
    auto backwardMove = listOfGameMoves[currentMoveIndex() - 1];
    auto move = backwardMove->getConvertToBackwardMove();

    auto wasMoveMade = makeMoveWithoutLegalChecks(move);

    if (wasMoveMade) {
        currentMoveIndex(currentMoveIndex() - 1);
    }

    return move;
}

std::shared_ptr<Move> ReplayGame::makeMoveForward()
{
    if (currentMoveIndex() == listOfGameMoves.size()) {
        return NULL;
    }
    auto move = listOfGameMoves[currentMoveIndex()];
    auto wasMoveMade = makeMoveWithoutLegalChecks(move);

    if (wasMoveMade) {
        currentMoveIndex(currentMoveIndex() + 1);
    }

    return move;
}
