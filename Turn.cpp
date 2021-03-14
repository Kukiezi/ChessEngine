#include "Turn.h"

Turn::Turn(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    turn_ = Color::White;
    setPlainText(QString("Turn: ") + QString::fromUtf8(getTurn()));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times", 16));
}

void Turn::setTurn(Color turn)
{
    turn_ = turn;
    setPlainText(QString("Turn: ") + QString::fromUtf8(getTurn()));
}

std::string Turn::getTurn()
{
    if (turn_ == Color::White) {
        return "White";
    }
    return "Black";
}
