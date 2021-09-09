#pragma once

#include "QBoardSquare.h"

class QMove
{
    QBoardSquare* from_;
    QBoardSquare* to_;
public:
    QBoardSquare* from() {return from_;}
    void from(QBoardSquare* from) {from_ = from;}
    QBoardSquare* to() {return to_;}
    void to(QBoardSquare* to) {to_ = to;}
};
