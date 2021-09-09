#ifndef QSAVEDGAMES_H
#define QSAVEDGAMES_H
#include "QSavedGame.h"
#include <QDirIterator>
#include "QEngine.h"

class QSavedGames
{
    std::list<QSavedGame*> savedGames_;
public:
    std::list<QSavedGame*>& savedGames() {return savedGames_;}

    QSavedGames();
private:
    void readSavedGamesFromFiles();

};

#endif // QSAVEDGAMES_H
