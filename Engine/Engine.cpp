#include "Engine.h"

void Engine::startGame(std::__1::string fenString)
{
    setGame(std::unique_ptr<Game>(new Game(fenString)));
}

ChessBoard* Engine::getChessBoard() const
{
    return game_->getChessBoard();
}

void Engine::makeMove(std::string move)
{
    getGame()->makeMove(move);
}

Game* Engine::getGame()
{
    return game_.get();
}

void Engine::setGame(std::unique_ptr<Game> game)
{
    game_ = std::move(game);
}
