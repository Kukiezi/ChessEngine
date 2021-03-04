#include "Board.h"
#include <QPainter>
#include <QImage>

Board::Board()
{
    int x = 0;
    int y = 0;
    int currentColumn = 0;
    Color currentColor = Color::White;

    for (int i = 0; i < 64; i++) {
        if (currentColumn == 8) {
            x = 0;
            y += BoardRect::rectSize;
            currentColumn = 0;
        }
        currentColor = getNextColor(currentColor, currentColumn);

        this->boardRects.push_back(new BoardRect(currentColor, x, y));

        currentColumn++;
        x += BoardRect::rectSize;
    }
}

Color Board::getNextColor(Color currentColor, int currentColumn)
{
    if (currentColumn == 0) {
        return currentColor;
    }

    if (currentColor == Color::White) {
        return Color::Brown;
    }

    return Color::White;
}
