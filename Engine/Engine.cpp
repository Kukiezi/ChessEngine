#include "Engine.h"

void Engine::startGame(std::__1::string fenString)
{
    setGame(std::unique_ptr<Game>(new Game(fenString)));
}

ChessBoard* Engine::getChessBoard() const
{
    return game_->getChessBoard();
}

bool Engine::makeMove(std::string move)
{
    return getGame()->makeMove(getGame()->createMove(move));
    game_->printChessBoard();
}

bool Engine::makeMove(std::pair<int, int> from, std::pair<int, int> to)
{
    std::cout << from.first << from.second << " " << to.first << to.second << std::endl;
    bool didMoveHappen = getGame()->makeMove(getGame()->createMove(from, to));
    game_->printChessBoard();
    return didMoveHappen;
}

std::shared_ptr<Move> Engine::getAIMove()
{
    return this->getGame()->getAIMove();
}

Color Engine::getTurn()
{
    return getGame()->getTurn();
}

Game* Engine::getGame()
{
    return game_.get();
}

void Engine::setGame(std::unique_ptr<Game> game)
{
    game_ = std::move(game);
}
