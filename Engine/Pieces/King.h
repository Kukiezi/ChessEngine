#ifndef KING_H
#define KING_H
#include "Piece.h"

class King: public Piece
{
    std::string name_ = "King";
    std::string shortName_ = "K";
    std::string image_;
    int value_ = 0;
    bool moved_ = false;
    std::vector<std::vector<int>> directionsOffsets_ = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, -1}, {-1, 1}, {1, 1}, {-1, -1}};

public:
    King(Color color);

    bool didPieceMove() const override;
    void setMoved(bool moved) override;
    std::string getName() const override;
    std::string getShortName() const override;
    std::vector<std::vector<int>> getDirectionsOffsets() const override;
    int getValue() const override;
};

#endif // KING_H
