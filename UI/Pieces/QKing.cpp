#include "QKing.h"

QKing::QKing(Color color) : QPiece(color)
{
    this->setImage();
    this->setPixmap(QPixmap(QString::fromUtf8(this->getImage())));
}

std::string QKing::getName() const
{
    return this->name_;
}

std::string QKing::getImage() const
{
    return this->image_;
}

int QKing::getValue() const
{
    return this->value_;
}

void QKing::setImage()
{
    this->image_ = this->getColor() == Color::White ? ":images/wking.png" : ":images/bking.png";
}
