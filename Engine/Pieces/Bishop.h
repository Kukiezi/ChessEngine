#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.h"
#include <vector>

class Bishop: public Piece
{
    std::string name_ = "Bishop";
    std::string shortName_ = "B";
    std::string image_;
    int value_ = 3;
    std::vector<std::vector<int>> directionsOffsets_ = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    bool moved_ = false;

public:
    Bishop(Color color);

    bool didPieceMove() const override;
    void setMoved(bool moved) override;
    std::vector<std::vector<int>> getDirectionsOffsets() const override;
    std::string getName() const override;
    std::string getShortName() const override;
    int getValue() const override;
};

#endif // BISHOP_H
