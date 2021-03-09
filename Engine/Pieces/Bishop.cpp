#include "Bishop.h"

Bishop::Bishop(Color color) : Piece(color){}

bool Bishop::didPieceMove() const
{
    return moved_;
}

void Bishop::setMoved(bool moved)
{
    moved_ = moved;
}

std::vector<std::vector<int> > Bishop::getDirectionsOffsets() const
{
    return directionsOffsets_;
}

std::string Bishop::getName() const
{
    return name_;
}

std::string Bishop::getShortName() const
{
    return shortName_;
}

int Bishop::getValue() const
{
    return value_;
}
