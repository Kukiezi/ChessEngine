#ifndef TURN_H
#define TURN_H
#include <QGraphicsTextItem>
#include "Color.h"
#include <QFont>

class Turn: public QGraphicsTextItem
{
    Color turn_;
public:
    Turn(QGraphicsItem* parent = 0);
    void setTurn(Color turn);
    std::string getTurn();
};

#endif // TURN_H
