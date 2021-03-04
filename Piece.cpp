#include "Piece.h"

Piece::Piece(Color _color)
{
    setColor(_color);
    this->setPixmap(QPixmap("/Users/dknopik/Code/ChessEngine/queen.png"));
}

std::string Piece::getName() const
{
    return this->name_;
}

std::string Piece::getImage() const
{
    return this->image_;
}

int Piece::getValue() const
{
    return this->value_;
}

Color Piece::getColor()
{
    return this->color_;
}

void Piece::setColor(Color color)
{
    color_ = color;
}

void Piece::print()
{
    std::cout << getName() << " " << getValue() << " " << getColorText() << std::endl;
}

std::string Piece::getColorText()
{
    if (getColor() == Color::White) {
        return "White";
    }
    return "Black";
}
