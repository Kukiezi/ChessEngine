#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <vector>
#include "../../Color.h"

//!  A piece base class.
/*!
  This class represent a chess piece. It provides abstraction for all the pieces.
*/
class Piece
{
std::string name_;
std::string shortName_;
Color color_;
int value_;
std::vector<std::vector<int>> directionsOffsets_;
bool moved_;

public:
    //! A constructor.
    /*!
      This constructor accepts color and calls parent's constructor to initiate the Piece color.
    */
    Piece(Color color);

    virtual std::vector<std::vector<int>> getDirectionsOffsets() const;
    virtual std::string getName() const;
    virtual void setName(std::string name);

    virtual std::string getShortName() const;

    virtual Color getColor() const;
    virtual void setColor(Color color);

    virtual int getValue() const;
    virtual void setValue(int value);

    virtual bool didPieceMove() const;
    virtual void setMoved(bool moved);
};

#endif // PIECE_H
