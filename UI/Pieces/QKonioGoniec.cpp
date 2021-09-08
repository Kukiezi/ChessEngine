#include "QKonioGoniec.h"

QKonioGoniec::QKonioGoniec(Color color) : QPiece(color)
{
    this->setImage();
    this->setPixmap(QPixmap(QString::fromUtf8(this->getImage())));
}

std::string QKonioGoniec::getName() const
{
    return this->name_;
}

std::string QKonioGoniec::getImage() const
{
    return this->image_;
}

int QKonioGoniec::getValue() const
{
    return this->value_;
}

void QKonioGoniec::setImage()
{
    this->image_ = this->getColor() == Color::White ? ":images/wknight.png" : ":images/bknight.png";
}
