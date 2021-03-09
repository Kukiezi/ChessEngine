#ifndef QBISHOP_H
#define QBISHOP_H
#include "QPiece.h"

class QBishop: public QPiece
{
    std::string name_ = "Bishop";
    std::string image_;
    int value_ = 3;
public:
    QBishop(QGraphicsScene* scene, Color color);

    std::string getName() const override;
    std::string getImage() const override;
    int getValue() const override;

    void setImage() override;
};

#endif // QBISHOP_H
