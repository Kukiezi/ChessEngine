#ifndef QUEEN_H
#define QUEEN_H
#include "Piece.h"
#include <vector>

class Queen: public Piece
{
    std::string name_ = "Queen";
    std::string shortName_ = "Q";
    std::string image_;
    int value_ = 9;
    std::vector<std::vector<int>> directionsOffsets_ = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, 1}, {1, -1}, {-1, 1}};
    bool moved_ = false;
public:
    Queen(Color color);

    bool didPieceMove() const override;
    void setMoved(bool moved) override;
    std::string getName() const override;
    std::vector<std::vector<int>> getDirectionsOffsets() const override;
    std::string getShortName() const override;
    int getValue() const override;
};

#endif // QUEEN_H
