#ifndef KING_H
#define KING_H
#include "Piece.h"

//!  A piece class.
/*!
  This class represent a chess piece called King. It is a simple class that defined neccesary getters and setters.
*/
class King: public Piece
{
    std::string name_ = "King";
    std::string shortName_ = "K";
    std::string image_;
    int value_ = 0;
    bool moved_ = false;
    std::vector<std::vector<int>> directionsOffsets_ = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, -1}, {-1, 1}, {1, 1}, {-1, -1}};

public:
    //! A constructor.
    /*!
      This constructor accepts color and calls parent's constructor to initiate the Piece color.
    */
    King(Color color);

    //! Public Methods.
    /*!
      Getters and Setters for the private fields.
    */
    bool didPieceMove() const override;
    void setMoved(bool moved) override;
    std::string getName() const override;
    std::string getShortName() const override;
    std::vector<std::vector<int>> getDirectionsOffsets() const override;
    int getValue() const override;
};

#endif // KING_H
