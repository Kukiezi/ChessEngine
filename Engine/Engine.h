#ifndef ENGINE_H
#define ENGINE_H
#include <string>
#include "Game.h"
#include "ReplayGame.h"
#include <filesystem>
#include <QDirIterator>

class Engine
{
std::unique_ptr<Game> game_;
std::unique_ptr<ReplayGame> replayGame_;

public:
    void startGame(std::string fenString = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR", GameType gameType = GameType::NORMAL);
    void startReplay(std::string gameFilePath, std::string fenString = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
    bool makeMove(std::string move);
    bool makeMove(std::pair<int, int> from, std::pair<int, int> to);
    std::shared_ptr<Move> getAIMove();
    Color getTurn();
    ChessBoard* getChessBoard() const;
    Game* getGame();
    std::shared_ptr<Move> makeMoveForward();
    std::shared_ptr<Move> makeMoveBackward();
    std::list<std::map<std::string, std::string>> getSavedGames();
    GameType getGameType();
private:
    void setGame(std::unique_ptr<Game> game);
    void setReplayGame(std::unique_ptr<ReplayGame> replayGame);
    void readGameFromFile(std::string gameFilePath, std::list<std::string>& list);
};

#endif // ENGINE_H
