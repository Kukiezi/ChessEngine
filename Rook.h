#ifndef ROOK_H
#define ROOK_H
#include "Piece.h"

class Rook: public Piece
{
    std::string name_ = "Rook";
    std::string image_ = "queen.png";
    int value_ = 9;
public:
    Rook(Color color);

    std::string getName() const;
    std::string getImage() const;
    int getValue() const;
};

#endif // ROOK_H
