#ifndef QUEEN_H
#define QUEEN_H
#include "Piece.h"
#include <vector>

//!  A piece class.
/*!
  This class represent a chess piece called Queen It is a simple class that defined neccesary getters and setters.
*/
class Queen: public Piece
{
    std::string name_ = "Queen";
    std::string shortName_ = "Q";
    std::string image_;
    int value_ = 9;
    std::vector<std::vector<int>> directionsOffsets_ = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
    bool moved_ = false;
public:
    //! A constructor.
    /*!
      This constructor accepts color and calls parent's constructor to initiate the Piece color.
    */
    Queen(Color color);

    //! Public Methods.
    /*!
      Getters and Setters for the private fields.
    */
    bool didPieceMove() const override;
    void setMoved(bool moved) override;
    std::string getName() const override;
    std::vector<std::vector<int>> getDirectionsOffsets() const override;
    std::string getShortName() const override;
    int getValue() const override;
};

#endif // QUEEN_H
