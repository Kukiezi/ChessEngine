#include "Turn.h"

Turn::Turn(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    turn_ = Color::White;
    setPlainText(QString("Turn: ") + QString::fromUtf8(getTurn()));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times", 24));
    setPos(850, 100);
}

void Turn::setTurn(Color turn)
{
    turn_ = turn;
    setPlainText(QString::fromUtf8(getTurn()));
}

std::string Turn::getTurn()
{
    if (turn_ == Color::White) {
        return "Turn: White";
    }
    if (turn_ == Color::Black) {
        return "Turn: Black";
    }
    if (turn_ == Color::DRAW) {
        return "DRAW";
    }
    if (turn_ == Color::WHITE_WON) {
        return "WHITE WON";
    }
    if (turn_ == Color::BLACK_WON) {
        return "BLACK WON";
    }
}
