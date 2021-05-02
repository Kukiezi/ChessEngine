#ifndef MOVE_H
#define MOVE_H
#include "BoardSquare.h"
#include "ChessBoard.h"
#include <map>

class Move
{
public:
    std::map<char, int> fieldCharToIndex = {
        {'a', 0},
        {'b', 1},
        {'c', 2},
        {'d', 3},
        {'e', 4},
        {'f', 5},
        {'g', 6},
        {'h', 7},
    };

    std::map<int, char> indexToFieldChar = {
        {0, 'a'},
        {1, 'b'},
        {2, 'c'},
        {3, 'd'},
        {4, 'e'},
        {5, 'f'},
        {6, 'g'},
        {7, 'h'},
    };

    std::pair<int, int> from;
    std::pair<int, int> to;
    std::unique_ptr<ChessBoard> chessBoard;
    bool isCastleMove;
    std::pair<int, int> castleFrom;
    std::pair<int, int> castleTo;


    Move(std::string move);
    Move(std::pair<int, int> from, std::pair<int, int> to, bool castle = false);

    void setMove(std::string move);
    bool isMoveCoordinatesValid();

    bool isEqual(Move* move);

    std::pair<int, int> getBoardCoordinatesFromChessCoordinates(std::string);
    std::string getChessCoordinatesFromBoardCoordinates();
    std::shared_ptr<Move> getConvertToBackwardMove();
};

#endif // MOVE_H
