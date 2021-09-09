#include "Engine.h"

void Engine::startGame(std::__1::string fenString, GameType gameType)
{
    setGame(std::unique_ptr<Game>(new Game(fenString, gameType)));
}

void Engine::startReplay(std::string gameFilePath, std::string fenString)
{
    std::list<std::string> list;
    readGameFromFile(gameFilePath, list);
    setReplayGame(std::unique_ptr<ReplayGame>(new ReplayGame(list, fenString)));
    setGame(replayGame_->getGame());
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

std::shared_ptr<Move> Engine::makeMoveForward()
{
    return replayGame_->makeMoveForward();
}

std::shared_ptr<Move> Engine::makeMoveBackward()
{
    return replayGame_->makeMoveBackward();
}

void Engine::setGame(std::unique_ptr<Game> game)
{
    game_ = std::move(game);
}

void Engine::setReplayGame(std::unique_ptr<ReplayGame> replayGame)
{
    replayGame_ = std::move(replayGame);
}

std::list<std::map<std::string, std::string>> Engine::getSavedGames()
{
    std::list<std::map<std::string, std::string>> savedGamesMap;
    QDirIterator it(QDir::currentPath(), QDirIterator::Subdirectories);

    while (it.hasNext()) {
        auto savedGame = it.next();
        auto position = savedGame.indexOf("/Game");
        if (position == -1) {
            continue;
        }
        QString gameNameInQString =  savedGame.mid(position + 1);
        std::string gameFileName = gameNameInQString.toUtf8().constData();
        auto gameFileExtensionPos = gameFileName.find(".txt");
        std::string gameName = gameFileName.substr(0, gameFileExtensionPos);
        std::map<std::string, std::string> gameMap = {
            {"name", gameName},
            {"path", savedGame.toUtf8().constData()},
        };
        savedGamesMap.push_back(gameMap);
    }
    return savedGamesMap;
}

bool Engine::isGameOver()
{
    getGame()->isGameOver();
}

GameType Engine::getGameType()
{
    return getGame()->gameType();
}

void Engine::readGameFromFile(std::string gameFilePath, std::list<std::string>& list)
{
    std::ifstream file(gameFilePath);

    std::string str;
    while (std::getline(file, str))
    {
        list.push_back(str);
    }
}
