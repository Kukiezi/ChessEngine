#include "Queen.h"

Queen::Queen(Color color) : Piece(color){}

bool Queen::didPieceMove() const
{
    return moved_;
}

void Queen::setMoved(bool moved)
{
    moved_ = moved;
}

std::string Queen::getName() const
{
    return this->name_;
}

std::vector<std::vector<int> > Queen::getDirectionsOffsets() const
{
    return directionsOffsets_;
}

std::string Queen::getShortName() const
{
    return this->shortName_;
}

int Queen::getValue() const
{
    return this->value_;
}
