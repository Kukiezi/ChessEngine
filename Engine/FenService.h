#ifndef FENSERVICE_H
#define FENSERVICE_H
#include <string>
#include "ChessBoard.h"
#include "Pieces/Pieces.h"

//!  A class that implements FEN methods
/*!
  This class provides methods that are needed to decode/read FEN strings.
*/
class FanService
{
public:
    static void addPieceToBoardFromFenString(std::string fenString, std::shared_ptr<ChessBoard>& board);
    static std::unique_ptr<Piece> getPieceFromFen(char piece);
    static std::string getStartingTurnFromFenString(std::string fenString);
};

#endif // FENSERVICE_H
