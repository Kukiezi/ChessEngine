#include "QBishop.h"

QBishop::QBishop(Color color) : QPiece(color)
{
    this->setImage();
    this->setPixmap(QPixmap(QString::fromUtf8(this->getImage())));
}

std::string QBishop::getName() const
{
    return this->name_;
}

std::string QBishop::getImage() const
{
    return this->image_;
}

int QBishop::getValue() const
{
    return this->value_;
}

void QBishop::setImage()
{
    this->image_ = this->getColor() == Color::White ? ":images/wbishop.png" : ":images/bbishop.png";
}
