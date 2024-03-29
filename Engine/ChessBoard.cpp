#include "ChessBoard.h"

ChessBoard::ChessBoard() : boardSquares_(8, std::vector<BoardSquare *>(8))
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) {
                boardSquares_[i][j] = new BoardSquare(Color::White, i, j);
            } else {
                boardSquares_[i][j] = new BoardSquare(Color::Brown, i, j);
            }
        }
    }
}



void ChessBoard::printChessBoard()
{
    std::cout << "" << std::endl;
    for (int i = boardSquares_.size() - 1; i >= 0; i--)
       {
           for (int j = 0; j < boardSquares_.size(); j++)
           {
               std::cout << boardSquares_[i][j]->getPieceColorShortName() << boardSquares_[i][j]->getPieceShortName();
               if (boardSquares_[i][j]->getPieceColorShortName() == "") {
                   std::cout << "  ";
               } else {
                   std::cout << " ";
               }
           }
           std::cout << std::endl;
       }
}
