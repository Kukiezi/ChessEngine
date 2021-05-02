#pragma once

#include "QPiece.h"

class QBishop: public QPiece
{
    std::string name_ = "Bishop";
    std::string image_;
    int value_ = 3;
public:
    QBishop(Color color);

    std::string getName() const override;
    std::string getImage() const override;
    int getValue() const override;

    void setImage() override;
};

