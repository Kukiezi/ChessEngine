#ifndef QKNIGHT_H
#define QKNIGHT_H
#include "QPiece.h"

class QKnight: public QPiece
{
    std::string name_ = "Knight";
    std::string image_;
    int value_ = 3;
public:
    QKnight(QGraphicsScene* scene, Color color);

    std::string getName() const override;
    std::string getImage() const override;
    int getValue() const override;

    void setImage() override;
};

#endif // QKNIGHT_H
