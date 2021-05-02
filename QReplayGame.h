#ifndef QREPLAYGAME_H
#define QREPLAYGAME_H
#include "QGame.h"
#include "QMove.h"

class QReplayGame : public QGame
{
public:
    void MakeMoveBackward();
    void MakeMoveForward();
};

#endif // QREPLAYGAME_H
