#ifndef QQUEEN_H
#define QQUEEN_H
#include "QPiece.h"

class QQueen: public QPiece
{
    std::string name_ = "Queen";
    std::string image_;
    int value_ = 9;
public:
    QQueen(QGraphicsScene* scene, Color color);

    std::string getName() const override;
    std::string getImage() const override;
    int getValue() const override;

    void setImage() override;
};

#endif // QQUEEN_H
