#include "QRook.h"

QRook::QRook(QGraphicsScene* scene, Color color) : QPiece(scene, color)
{
    this->setImage();
    this->setPixmap(QPixmap(QString::fromUtf8(this->getImage())));
}

std::string QRook::getName() const
{
    return this->name_;
}

std::string QRook::getImage() const
{
    return this->image_;
}

int QRook::getValue() const
{
    return this->value_;
}

void QRook::setImage()
{
    this->image_ = this->getColor() == Color::White ? ":images/wrook.png" : ":images/brook.png";
}
