#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <vector>
#include "BoardSquare.h"
#include <iostream>
#include <deque>

//!  A class that represent a Chess Board.
/*!
  This class provides necessary fields and funcionalities to manage Chess Board square and piece on it.
*/
class ChessBoard
{
public:
    std::vector<std::vector<BoardSquare*>> boardSquares;
    std::vector<std::vector<int>> directionsOffsets = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, 1}, {1, -1}, {-1, 1}};

    //! A constructor.
    /*!
      Initiate the whole Board with empty BoardSquares. Assign correct colors.
    */
    ChessBoard();

    //! A testing vizual method.
    /*!
      Show the current state of the board via print to the console.
    */
    void printChessBoard();
};


#endif // CHESSBOARD_H
