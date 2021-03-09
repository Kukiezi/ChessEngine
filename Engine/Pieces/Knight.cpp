#include "Knight.h"

Knight::Knight(Color color) : Piece(color){}

bool Knight::didPieceMove() const
{
    return moved_;
}

void Knight::setMoved(bool moved)
{
    moved_ = moved;
}

std::string Knight::getName() const
{
    return this->name_;
}

std::string Knight::getShortName() const
{
    return this->shortName_;
}

std::vector<std::vector<int> > Knight::getDirectionsOffsets() const
{
    return directionsOffsets_;
}

int Knight::getValue() const
{
    return this->value_;
}
