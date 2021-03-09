#include "Rook.h"

Rook::Rook(Color color) : Piece(color){}

bool Rook::didPieceMove() const
{
    return moved_;
}

void Rook::setMoved(bool moved)
{
    moved_ = moved;
}

std::string Rook::getName() const
{
    return this->name_;
}

std::vector<std::vector<int> > Rook::getDirectionsOffsets() const
{
    return directionsOffsets_;
}

std::string Rook::getShortName() const
{
    return this->shortName_;
}

int Rook::getValue() const
{
    return this->value_;
}
