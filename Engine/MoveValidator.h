#ifndef MOVEVALIDATOR_H
#define MOVEVALIDATOR_H
#include "ChessBoard.h"
#include "Move.h"
#include "MoveGenerator.h"

//!  A class that generates chess moves.
/*!
  This class generates moves on the board.
*/
class MoveValidator
{
public:
    //! Determine if move is legal based on coordinates
    /*!
      This method will return true if move is in valid coordinates and false if not.
      \param chessBoard as ChessBoard pointer.
      \param move as Move shared pointer.
      \param friendlyPieceColor as Color.
    */
    static bool isMoveLegal(ChessBoard* chessBoard, std::shared_ptr<Move> move, Color friendlyPieceColor);
    static bool isGameOver(ChessBoard* chessBoard, Color friendlyPieceColor);
    //! Get All legal moves.
    /*!
      Uses generator to get all legal moves. Then tests all the moves to check for King Checks and returns all legal moves.
      \param chessBoard as ChessBoard pointer.
      \param friendlyPieceColor as Color.
    */
    static std::list<Move*> getAllLegalMoves(ChessBoard* chessBoard, Color friendlyPieceColor);
private:
    static bool isPieceOnStartingSquareFriendly(std::shared_ptr<Piece> piece, Color friendlyPieceColor);
};

#endif // MOVEVALIDATOR_H
