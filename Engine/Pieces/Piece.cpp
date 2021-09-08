#include "Piece.h"

Piece::Piece(Color color)
{
    setColor(color);
}

std::vector<std::vector<int> > Piece::getDirectionsOffsets() const
{
    return directionsOffsets_;
}

std::vector<std::vector<int> > Piece::getSlidingDirectionsOffsets() const
{
    return slidingDirectionsOffsets_;
}

std::string Piece::getName() const
{
    return name_;
}

void Piece::setName(std::string name)
{
    name_ = name;
}

std::string Piece::getShortName() const
{
    return shortName_;
}

Color Piece::getColor() const
{
    return color_;
}

void Piece::setColor(Color color)
{
    color_ = color;
}

int Piece::getValue() const
{
    return value_;
}

void Piece::setValue(int value)
{
    value_ = value;
}

bool Piece::didPieceMove() const
{
    return moved_;
}

void Piece::setMoved(bool moved)
{
    moved_ = moved;
}
