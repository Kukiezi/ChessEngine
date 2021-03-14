#ifndef BOARDSQUARE_H
#define BOARDSQUARE_H

#include "../Color.h"
#include "Pieces/Piece.h"

class BoardSquare
{
std::shared_ptr<Piece> piece_;
Color color_;

public:
    BoardSquare();
    BoardSquare(Color color);

    std::shared_ptr<Piece> getPiece();
    Piece getPieceCopy();
    void setPiece(std::shared_ptr<Piece>& piece);
    void setPiece(Piece piece);
    void resetPiece();

    Color getColor();
    void setColor(Color color);

    std::string getColorShortName();
    std::string getPieceColorShortName();
    std::string getPieceShortName();
};

#endif // BOARDSQUARE_H
