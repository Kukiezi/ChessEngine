#include "FenService.h"

void FanService::addPieceToBoardFromFenString(std::__1::string fenString, std::shared_ptr<ChessBoard>& chessBoard)
{
    int count = 0;
    int skip = 0;

    for (int i = chessBoard->boardSquares.size() - 1; i >= 0; i--)
       {
           for (int j = 0; j < chessBoard->boardSquares.size(); j++)
           {
               if (fenString[count] == '/') {
                   count++;
               }

               if (skip > 0) {
                   skip--;
                   continue;
               }

               if (isdigit(fenString[count])) {
                   skip = (int)fenString[count++] - '0' - 1;
                   continue;
               }

               std::shared_ptr<Piece> pieceToAdd = getPieceFromFen(fenString[count++]);
               if (pieceToAdd != nullptr) {
                   chessBoard->boardSquares[i][j]->setPiece(pieceToAdd);
               }
           }
       }
}

std::unique_ptr<Piece> FanService::getPieceFromFen(char piece)
{
    switch(piece)
    {
        case 'r':
            return std::make_unique<Rook>(Color::Black);
            break;
        case 'R':
            return std::make_unique<Rook>(Color::White);
            break;
        case 'n':
            return std::make_unique<Knight>(Color::Black);
            break;
        case 'N':
            return std::make_unique<Knight>(Color::White);
            break;
        case 'b':
            return std::make_unique<Bishop>(Color::Black);
            break;
        case 'B':
            return std::make_unique<Bishop>(Color::White);
            break;
        case 'q':
             return std::make_unique<Queen>(Color::Black);
            break;
        case 'Q':
            return std::make_unique<Queen>(Color::White);
            break;
        case 'k':
            return std::make_unique<King>(Color::Black);
            break;
        case 'K':
            return std::make_unique<King>(Color::White);
            break;
        case 'p':
            return std::make_unique<Pawn>(Color::Black);
            break;
        case 'P':
            return std::make_unique<Pawn>(Color::White);
            break;
        default:
            return nullptr;
    }
}

