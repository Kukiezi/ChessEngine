#include "QChessBoard.h"
#include <QPainter>
#include <QImage>

QChessBoard::QChessBoard() : boardSquares(8, std::vector<QBoardSquare *>(8))
{
    int x = 0;
    int y = 0;


    for (int i = 0; i < 8; i++) {
        x = 0;
        y += QBoardSquare::rectSize;

        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) {
                boardSquares[i][j] = new QBoardSquare(Color::White, x, y);
            } else {
                boardSquares[i][j] = new QBoardSquare(Color::Brown, x, y);
            }
            x += QBoardSquare::rectSize;
        }
    }
}

Color QChessBoard::getNextColor(Color currentColor, int currentColumn)
{
    if (currentColumn == 0) {
        return currentColor;
    }

    if (currentColor == Color::White) {
        return Color::Brown;
    }

    return Color::White;
}
