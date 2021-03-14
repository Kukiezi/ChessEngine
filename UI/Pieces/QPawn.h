#pragma once

#include "QPiece.h"

class QPawn: public QPiece
{
    std::string name_ = "Pawn";
    std::string image_;
    int value_ = 1;
public:
    QPawn(QGraphicsScene* scene, Color color);

    std::string getName() const override;
    std::string getImage() const override;
    int getValue() const override;

    void setImage() override;
};

