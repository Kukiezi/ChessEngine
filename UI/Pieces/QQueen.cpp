#include "QQueen.h"

QQueen::QQueen(QGraphicsScene* scene, Color color) : QPiece(scene, color)
{
    this->setImage();
    this->setPixmap(QPixmap(QString::fromUtf8(this->getImage())));
}

std::string QQueen::getName() const
{
    return this->name_;
}

std::string QQueen::getImage() const
{
    return this->image_;
}

int QQueen::getValue() const
{
    return this->value_;
}

void QQueen::setImage()
{
    this->image_ = this->getColor() == Color::White ? ":images/wqueen.png" : ":images/bqueen.png";
}
