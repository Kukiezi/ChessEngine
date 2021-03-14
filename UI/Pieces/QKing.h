#pragma once

#include "QPiece.h"

class QKing: public QPiece
{
    std::string name_ = "King";
    std::string image_;
    int value_ = 0;
public:
    QKing(QGraphicsScene* scene, Color color);

    std::string getName() const override;
    std::string getImage() const override;
    int getValue() const override;

    void setImage() override;
};
