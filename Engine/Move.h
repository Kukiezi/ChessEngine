#ifndef MOVE_H
#define MOVE_H
#include "BoardSquare.h"
#include "ChessBoard.h"
#include <map>

//!  A class that represents single move in chess game.
/*!
  This class provides information about each move in the game of chess.
  Allow for different ways to read the move and perform the move.
*/
class Move
{
    std::map<char, int> fieldCharToIndex = {
        {'a', 0},
        {'b', 1},
        {'c', 2},
        {'d', 3},
        {'e', 4},
        {'f', 5},
        {'g', 6},
        {'h', 7},
    };

    std::map<int, char> indexToFieldChar = {
        {0, 'a'},
        {1, 'b'},
        {2, 'c'},
        {3, 'd'},
        {4, 'e'},
        {5, 'f'},
        {6, 'g'},
        {7, 'h'},
    };
    std::pair<int, int> from_;
    std::pair<int, int> to_;
    std::unique_ptr<ChessBoard> chessBoard_;
    bool isCastleMove_;
    std::pair<int, int> castleFrom_;
    std::pair<int, int> castleTo_;
public:
    std::pair<int, int> from() const & {return from_; }
    void from(std::pair<int, int> from) {from_ = from;}

    std::pair<int, int> to() const & {return to_; }
    std::pair<int, int> to(std::pair<int, int> to) {to_ = to;}

    std::pair<int, int> castleFrom() const & {return castleFrom_; }
    void castleFrom(std::pair<int, int> castleFrom) {castleFrom_ = castleFrom;}

    std::pair<int, int> castleTo() const & {return castleTo_; }
    std::pair<int, int> castleTo(std::pair<int, int> castleTo) {castleTo_ = castleTo;}

    bool isCastleMove() const {return isCastleMove_; }
    void isCastleMove(bool isCastleMove) {isCastleMove_ = isCastleMove;}

    std::unique_ptr<ChessBoard> & chessBoard() {return chessBoard_;}

    //! A constructor.
    /*!
      Based on given move string, create move pairs of integers. Example string: e2e4
      \param move as string.
    */
    Move(std::string move);

    //! A second constructor.
    /*!
      Based on given move pairs, decides if this is a castle move and saves the move with castle flag.
      \param from as pair<int, int>.
      \param to as pair<int, int>.
    */
    Move(std::pair<int, int> from, std::pair<int, int> to);

    void setMove(std::string move);

    //! Validation method.
    /*!
      Validate if provided move is legal based on coordinates provided.
    */
    bool isMoveCoordinatesValid();

    //! Move comparator.
    /*!
      Comparing if this and provided move are the same.
      \param move as Move ptr.
    */
    bool isEqual(Move* move);

    //! Move converter.
    /*!
      Converts chess board string position to board coordinates as pair of integers. Example: e2 => pair<1, 4>
      \param coordinates as a string.
    */
    std::pair<int, int> getBoardCoordinatesFromChessCoordinates(std::string coordinates);

    //! Move converter.
    /*!
      Converts chess board coordinates to chess board string position. Example: pair<1, 4> => e2
    */
    std::string getChessCoordinatesFromBoardCoordinates();

    //! Move converter.
    /*!
      Convert current move to backward move. Used in Replays.
    */
    std::shared_ptr<Move> getConvertToBackwardMove();
};

#endif // MOVE_H
