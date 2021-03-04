#ifndef BOARD_H
#define BOARD_H
#include "BoardRect.h"
#include "Pieces.h"

class Board
{
public:
    std::vector<BoardRect*> boardRects;
    Piece* piece = new Queen(Color::White);
    Board();

private:
    Color getNextColor(Color currentColor, int currentColumn);
};

#endif // BOARD_H
