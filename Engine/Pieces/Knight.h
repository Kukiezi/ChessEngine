#ifndef KNIGHT_H
#define KNIGHT_H
#include <list>
#include "Piece.h"


class Knight: public Piece
{
    std::string name_ = "Knight";
    std::string shortName_ = "N";
    std::string image_;
    int value_ = 3;
    std::vector<std::vector<int>> directionsOffsets_ = {{-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}};
    bool moved_ = false;

public:
    Knight(Color color);

    bool didPieceMove() const override;
    void setMoved(bool moved) override;
    std::string getName() const override;
    std::string getShortName() const override;
    std::vector<std::vector<int>> getDirectionsOffsets() const override;
    int getValue() const override;
};

#endif // KNIGHT_H
