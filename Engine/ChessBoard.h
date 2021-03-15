#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <vector>
#include "BoardSquare.h"
#include <iostream>
#include <deque>

class ChessBoard
{
public:
    std::vector<std::vector<BoardSquare*>> boardSquares;
    std::vector<std::vector<int>> directionsOffsets = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, 1}, {1, -1}, {-1, 1}};

    ChessBoard();

    void printChessBoard();
};


#endif // CHESSBOARD_H
