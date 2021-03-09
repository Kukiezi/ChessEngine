#include "QKnight.h"

QKnight::QKnight(QGraphicsScene* scene, Color color) : QPiece(scene, color)
{
    this->setImage();
    this->setPixmap(QPixmap(QString::fromUtf8(this->getImage())));
}

std::string QKnight::getName() const
{
    return this->name_;
}

std::string QKnight::getImage() const
{
    return this->image_;
}

int QKnight::getValue() const
{
    return this->value_;
}

void QKnight::setImage()
{
    this->image_ = this->getColor() == Color::White ? ":images/wknight.png" : ":images/bknight.png";
}
