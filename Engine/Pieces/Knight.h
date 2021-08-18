#ifndef KNIGHT_H
#define KNIGHT_H
#include <list>
#include "Piece.h"

//!  A piece class.
/*!
  This class represent a chess piece called Knight It is a simple class that defined neccesary getters and setters.
*/
class Knight: public Piece
{
    std::string name_ = "Knight";
    std::string shortName_ = "N";
    std::string image_;
    int value_ = 3;
    std::vector<std::vector<int>> directionsOffsets_ = {{-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}};
    bool moved_ = false;

public:
    //! A constructor.
    /*!
      This constructor accepts color and calls parent's constructor to initiate the Piece color.
    */
    Knight(Color color);

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

#endif // KNIGHT_H
