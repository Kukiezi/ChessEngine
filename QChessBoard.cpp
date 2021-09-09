#include "QChessBoard.h"
#include <QPainter>
#include <QImage>

QChessBoard::QChessBoard() : boardSquares_(8, std::vector<QBoardSquare *>(8))
{
    int x = 0;
    int y = 0;


    for (int i = 7; i >= 0; i--) {
        x = 0;
        y += QBoardSquare::rectSize();

        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) {
                boardSquares()[i][j] = new QBoardSquare(Color::Brown, x, y, i, j);
            } else {
                boardSquares()[i][j] = new QBoardSquare(Color::White, x, y, i, j);
            }
            x += QBoardSquare::rectSize();
        }
    }
}

void QChessBoard::resetSquareColors()
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) {
                boardSquares()[i][j]->setColor(Color::Brown);
            } else {
                boardSquares()[i][j]->setColor(Color::White);
            }
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
