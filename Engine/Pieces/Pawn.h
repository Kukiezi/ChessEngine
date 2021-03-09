#ifndef PAWN_H
#define PAWN_H
#include "Piece.h"

class Pawn: public Piece
{
    std::string name_ = "Pawn";
    std::string shortName_ = "P";
    int value_ = 1;
    std::vector<std::vector<int>> directionsOffsets_ = {{1, 0}};
    bool moved_ = false;

public:
    Pawn(Color color);

    bool didPieceMove() const override;
    void setMoved(bool moved) override;
    std::string getName() const override;
    std::string getShortName() const override;
    int getValue() const override;

};

#endif // PAWN_H
