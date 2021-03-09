#ifndef QROOK_H
#define QROOK_H
#include "QPiece.h"

class QRook: public QPiece
{
    std::string name_ = "Rook";
    std::string image_;
    int value_ = 5;
public:
    QRook(QGraphicsScene* scene, Color color);

    std::string getName() const override;
    std::string getImage() const override;
    int getValue() const override;

    void setImage() override;
};

#endif // QROOK_H
