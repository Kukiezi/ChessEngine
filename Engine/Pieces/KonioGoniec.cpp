#include "KonioGoniec.h"

KonioGoniec::KonioGoniec(Color color) : Piece(color){}

bool KonioGoniec::didPieceMove() const
{
    return moved_;
}

void KonioGoniec::setMoved(bool moved)
{
    moved_ = moved;
}

std::string KonioGoniec::getName() const
{
    return this->name_;
}

std::string KonioGoniec::getShortName() const
{
    return this->shortName_;
}

std::vector<std::vector<int> > KonioGoniec::getDirectionsOffsets() const
{
    return directionsOffsets_;
}

std::vector<std::vector<int> > KonioGoniec::getSlidingDirectionsOffsets() const
{
    return slidingDirectionsOffsets_;
}

int KonioGoniec::getValue() const
{
    return this->value_;
}
