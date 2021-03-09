#include "Move.h"

Move::Move(std::__1::string move)
{
    setMove(move);
}

Move::Move(std::pair<int, int> from, std::pair<int, int> to)
{
    this->from = from;
    this->to = to;
}

void Move::setMove(std::string move)
{
    from = getBoardCoordinatesFromChessCoordinates(move.substr(0, 2));
    to = getBoardCoordinatesFromChessCoordinates(move.substr(2, move.size()));
}

bool Move::isMoveCoordinatesValid()
{
    if (
            this->from.first < 0 ||
            this->from.first > 7 ||
            this->from.second < 0 ||
            this->from.second > 7 ||
            this->to.first < 0 ||
            this->to.first > 7 ||
            this->to.second < 0 ||
            this->to.second > 7
    ) {
        return false;
    }

    return true;
}

bool Move::isEqual(Move *move)
{
    if (this->from.first == move->from.first &&
            this->from.second == move->from.second &&
            this->to.first == move->to.first &&
            this->to.second == move->to.second) {
        return true;
    }
    return false;
}

std::pair<int, int> Move::getBoardCoordinatesFromChessCoordinates(std::string coordinates)
{
    try {
        int row = (int)coordinates[1] - '0' - 1;
        int col = fieldCharToIndex.at(coordinates[0]);
        return std::make_pair(row, col);;
    }  catch (...) {
        return std::make_pair(-1, -1);
    }
}
