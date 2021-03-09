#include "Pawn.h"

Pawn::Pawn(Color color) : Piece(color){}

bool Pawn::didPieceMove() const
{
    return moved_;
}

void Pawn::setMoved(bool moved)
{
    moved_ = moved;
}

std::string Pawn::getName() const
{
    return this->name_;
}

std::string Pawn::getShortName() const
{
    return this->shortName_;
}

int Pawn::getValue() const
{
    return this->value_;
}
