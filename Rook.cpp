#include "Rook.h"

Rook::Rook(Color color) : Piece(color) {}

std::string Rook::getName() const
{
    return this->name_;
}

std::string Rook::getImage() const
{
    return this->image_;
}

int Rook::getValue() const
{
    return this->value_;
}
