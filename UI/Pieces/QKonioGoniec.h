#pragma once

#include "QPiece.h"

class QKonioGoniec: public QPiece
{
    std::string name_ = "KonioGoniec";
    std::string image_;
    int value_ = 3;
public:
    QKonioGoniec(Color color);

    std::string getName() const override;
    std::string getImage() const override;
    int getValue() const override;

    void setImage() override;
};
