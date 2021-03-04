#include "Queen.h"

Queen::Queen(Color color) : Piece(color) {}

std::string Queen::getName() const
{
    return this->name_;
}

std::string Queen::getImage() const
{
    return this->image_;
}

int Queen::getValue() const
{
    return this->value_;
}
