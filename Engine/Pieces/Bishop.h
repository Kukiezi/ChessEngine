#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.h"
#include <vector>

//!  A piece class.
/*!
  This class represent a chess piece called Bishop. It is a simple class that defined neccesary getters and setters.
*/
class Bishop: public Piece
{
    std::string name_ = "Bishop";
    std::string shortName_ = "B";
    std::string image_;
    int value_ = 3;
    std::vector<std::vector<int>> directionsOffsets_ = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    bool moved_ = false;

public:
    //! A constructor.
    /*!
      This constructor accepts color and calls parent's constructor to initiate the Piece color.
    */
    Bishop(Color color);

    //! Public Methods.
    /*!
      Getters and Setters for the private fields.
    */
    bool didPieceMove() const override;
    void setMoved(bool moved) override;
    std::vector<std::vector<int>> getDirectionsOffsets() const override;
    std::string getName() const override;
    std::string getShortName() const override;
    int getValue() const override;
};

#endif // BISHOP_H
