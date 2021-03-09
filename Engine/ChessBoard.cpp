#include "ChessBoard.h"

ChessBoard::ChessBoard() : boardSquares(8, std::vector<BoardSquare *>(8))
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) {
                boardSquares[i][j] = new BoardSquare(Color::White);
            } else {
                boardSquares[i][j] = new BoardSquare(Color::Brown);
            }
        }
    }
}

void ChessBoard::printChessBoard()
{
    std::cout << "" << std::endl;
    for (int i = boardSquares.size() - 1; i >= 0; i--)
       {
           for (int j = 0; j < boardSquares.size(); j++)
           {
               std::cout << boardSquares[i][j]->getPieceColorShortName() << boardSquares[i][j]->getPieceShortName();
               if (boardSquares[i][j]->getPieceColorShortName() == "") {
                   std::cout << "  ";
               } else {
                   std::cout << " ";
               }
           }
           std::cout << std::endl;
       }
}
