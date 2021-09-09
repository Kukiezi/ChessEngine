#include "QSavedGames.h"

extern Engine * engine;

QSavedGames::QSavedGames()
{
    auto savedGamesMap = engine->getSavedGames();
    int x = 0;
    int y = 100;
    int count = 0;
    for (auto game : savedGamesMap) {
        if (count > 4) {
            y += 150;
            x = 0;
            count = 0;
        }
        savedGames().push_back(new QSavedGame(game, std::make_pair(x, y)));
        count += 1;
        x += 250;
    }
}

void QSavedGames::readSavedGamesFromFiles()
{

}
