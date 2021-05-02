#pragma once

#include "QPiece.h"

class QQueen: public QPiece
{
    std::string name_ = "Queen";
    std::string image_;
    int value_ = 9;
public:
    QQueen(Color color);

    std::string getName() const override;
    std::string getImage() const override;
    int getValue() const override;

    void setImage() override;
};

