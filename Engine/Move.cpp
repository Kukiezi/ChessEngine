#include "Move.h"

Move::Move(std::__1::string move)
{
    setMove(move);
}

Move::Move(std::pair<int, int> from, std::pair<int, int> to)
{
    from_ = from;
    to_ = to;
    isCastleMove_ = false;
    if (from.first == 0 && from.second == 4 && to.first == 0 && to.second == 1) {
        isCastleMove_ = true;
        castleFrom_ = std::make_pair(0, 0);
        castleTo_ = std::make_pair(0, 2);
    } else if (from.first == 0 && from.second == 4 && to.first == 0 && to.second == 6) {
        isCastleMove_ = true;
        castleFrom_ = std::make_pair(0, 7);
        castleTo_ = std::make_pair(0, 5);
    } else if (from.first == 7 && from.second == 4 && to.first == 7 && to.second == 1) {
        isCastleMove_ = true;
        castleFrom_ = std::make_pair(7, 0);
        castleTo_ = std::make_pair(7, 2);
    } else if (from.first == 7 && from.second == 4 && to.first == 7 && to.second == 6) {
        isCastleMove_ = true;
        castleFrom_ = std::make_pair(7, 7);
        castleTo_ = std::make_pair(7, 5);
    }

}

void Move::setMove(std::string move)
{
    from_ = getBoardCoordinatesFromChessCoordinates(move.substr(0, 2));
    to_ = getBoardCoordinatesFromChessCoordinates(move.substr(2, move.size()));
}

bool Move::isMoveCoordinatesValid()
{
    if (
            this->from_.first < 0 ||
            this->from_.first > 7 ||
            this->from_.second < 0 ||
            this->from_.second > 7 ||
            this->to_.first < 0 ||
            this->to_.first > 7 ||
            this->to_.second < 0 ||
            this->to_.second > 7
    ) {
        return false;
    }

    return true;
}

bool Move::isEqual(Move *move)
{
    if (this->from_.first == move->from_.first &&
            this->from_.second == move->from_.second &&
            this->to_.first == move->to_.first &&
            this->to_.second == move->to_.second) {
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

std::string Move::getChessCoordinatesFromBoardCoordinates()
{
    char a = indexToFieldChar[this->from_.second];
    int b = this->from_.first + 1;

    char c = indexToFieldChar[this->to_.second];
    char d = this->to_.first + 1;
    std::string pgnMove = "";
    pgnMove = a + std::to_string(b) + c + std::to_string(d);
    return pgnMove;
}

std::shared_ptr<Move> Move::getConvertToBackwardMove()
{
    std::shared_ptr<Move> move (new Move(std::make_pair(this->to_.first, this->to_.second), std::make_pair(this->from_.first, this->from_.second)));
    return move;
}
