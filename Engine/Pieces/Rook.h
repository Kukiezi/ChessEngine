#ifndef ROOK_H
#define ROOK_H
#include "Piece.h"
#include <vector>

class Rook: public Piece
{
    std::string name_ = "Rook";
    std::string shortName_ = "R";
    std::string image_;
    int value_ = 5;
    std::vector<std::vector<int>> directionsOffsets_ = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    bool moved_ = false;

public:
    Rook(Color color);

    bool didPieceMove() const override;
    void setMoved(bool moved) override;
    std::string getName() const override;
    std::vector<std::vector<int>> getDirectionsOffsets() const override;
    std::string getShortName() const override;
    int getValue() const override;
};

#endif // ROOK_H
