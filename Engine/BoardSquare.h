#ifndef BOARDSQUARE_H
#define BOARDSQUARE_H

#include "../Color.h"
#include "Pieces/Piece.h"

//!  A class that represent a Square on ChessBoard.
/*!
  This class provides necessary fields and funcionalities to manage Chess Board square and piece on it.
*/
class BoardSquare
{
std::shared_ptr<Piece> piece_;
Color color_;
int row_;
int col_;

public:
    int row() const {return row_; }
    void row(int row) {
        if (row < 0 || row > 7) {
            throw std::invalid_argument("invalid argument for row");
        }
        row_ = row;
    }
    int col() const {return col_;}
    void col(int col) {
        if (col < 0 || col > 7) {
            throw std::invalid_argument("invalid argument for col");
        }
        col_ = col;
    }

    //! A constructor.
    /*!
      This constructor initiates White BoardSquare
    */
    BoardSquare();
    //! A second constructor.
    /*!
      This constructor accepts color and position on a board for current BoardSquare
      \param color as Color enum.
      \param row as an integer.
      \param col as an integer.
    */
    BoardSquare(Color color, int row, int col);

    std::shared_ptr<Piece> getPiece();
    Piece getPieceCopy();
    void setPiece(std::shared_ptr<Piece>& piece);
    void setPiece(Piece piece);

    //! Method that reset square piece.
    /*!
      This method has one purpose and it is to reset piece to null on this BoardSquare
    */
    void resetPiece();

    Color getColor();
    void setColor(Color color);

    std::string getColorShortName();
    std::string getPieceColorShortName();
    std::string getPieceShortName();
};

#endif // BOARDSQUARE_H
