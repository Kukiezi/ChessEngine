#ifndef QUEEN_H
#define QUEEN_H
#include "Piece.h"

class Queen: public Piece
{
    std::string name_ = "Queen";
    std::string image_ = "queen.png";
    int value_ = 9;
public:
    Queen(Color color);

    std::string getName() const;
    std::string getImage() const;
    int getValue() const;
};

#endif // QUEEN_H
