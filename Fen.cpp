#include "Fen.h"

void FenReader::addPiececToBoardRectFromFen(std::string fenString, QChessBoard* board, QGraphicsScene* scene)
{
//    int count = 0;
//    int skip = 0;
//    for (QBoardSquare* rect : board->boardSquares) {
//        if (fenString[count] == '/') {
//            count++;
//        }

//        if (skip > 0) {
//            skip--;
//            continue;
//        }

//        if (isdigit(fenString[count])) {
//            skip = (int)fenString[count++] - '0' - 1;
//            continue;
//        }

//        QPiece* pieceToAdd = getPieceFromFen(fenString[count++], scene);
//        if (pieceToAdd != NULL) {
//            rect->setPiece(pieceToAdd);
//        }
//    }
}

QPiece* FenReader::getPieceFromFen(char piece, QGraphicsScene* scene)
{
    switch(piece)
    {
        case 'r':
            return new QRook(Color::Black);
            break;
        case 'R':
            return new QRook(Color::White);
            break;
        case 'n':
            return new QKnight(Color::Black);
            break;
        case 'N':
            return new QKnight(Color::White);
            break;
        case 'b':
            return new QBishop(Color::Black);
            break;
        case 'B':
            return new QBishop(Color::White);
            break;
        case 'q':
            return new QQueen(Color::Black);
            break;
        case 'Q':
            return new QQueen(Color::White);
            break;
        case 'k':
            return new QKing(Color::Black);
            break;
        case 'K':
            return new QKing(Color::White);
            break;
        case 'p':
            return new QPawn(Color::Black);
            break;
        case 'P':
            return new QPawn(Color::White);
            break;
        default:
            return new QKing(Color::White);
    }
}
