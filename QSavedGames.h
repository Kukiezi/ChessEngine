#ifndef QSAVEDGAMES_H
#define QSAVEDGAMES_H
#include "QSavedGame.h"
#include <QDirIterator>
#include "QEngine.h"

class QSavedGames
{
public:
    std::list<QSavedGame*> savedGames;

    QSavedGames();
private:
    void readSavedGamesFromFiles();

};

#endif // QSAVEDGAMES_H
