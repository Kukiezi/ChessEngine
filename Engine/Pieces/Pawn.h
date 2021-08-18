#ifndef PAWN_H
#define PAWN_H
#include "Piece.h"

//!  A piece class.
/*!
  This class represent a chess piece called Pawn It is a simple class that defined neccesary getters and setters.
*/
class Pawn: public Piece
{
    std::string name_ = "Pawn";
    std::string shortName_ = "P";
    int value_ = 1;
    std::vector<std::vector<int>> directionsOffsets_ = {{1, 0}};
    bool moved_ = false;

public:
    //! A constructor.
    /*!
      This constructor accepts color and calls parent's constructor to initiate the Piece color.
    */
    Pawn(Color color);

    //! Public Methods.
    /*!
      Getters and Setters for the private fields.
    */
    bool didPieceMove() const override;
    void setMoved(bool moved) override;
    std::string getName() const override;
    std::string getShortName() const override;
    int getValue() const override;

};

#endif // PAWN_H
