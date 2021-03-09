#include "King.h"

King::King(Color color) : Piece(color){}

bool King::didPieceMove() const
{
    return moved_;
}

void King::setMoved(bool moved)
{
    moved_ = moved;
}

std::string King::getName() const
{
    return name_;
}

std::string King::getShortName() const
{
    return shortName_;
}

std::vector<std::vector<int> > King::getDirectionsOffsets() const
{
    return directionsOffsets_;
}

int King::getValue() const
{
    return value_;
}
