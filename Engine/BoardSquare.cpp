#include "BoardSquare.h"

BoardSquare::BoardSquare()
{
    setColor(Color::White);
}

BoardSquare::BoardSquare(Color color)
{
    setColor(color);
}

std::shared_ptr<Piece> BoardSquare::getPiece()
{
    return piece_;
}

Piece BoardSquare::getPieceCopy()
{
    return *piece_;
}

void BoardSquare::setPiece(std::shared_ptr<Piece>& piece)
{
    piece_ = piece;
}

void BoardSquare::resetPiece()
{
    piece_ = nullptr;
}


Color BoardSquare::getColor()
{
    return color_;
}

std::string BoardSquare::getColorShortName()
{
    return color_ == Color::White ? "w" : "b";
}

void BoardSquare::setColor(Color color)
{
    color_ = color;
}

std::string BoardSquare::getPieceColorShortName()
{
    auto piece = getPiece();
    if (piece == nullptr) {
        return "";
    }

    return piece->getColor() == Color::White ? "w" : "b";
}

std::string BoardSquare::getPieceShortName()
{
    auto piece = getPiece();

    return piece != nullptr ? getPiece()->getShortName() : "x";
}

