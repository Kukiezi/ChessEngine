#include "QPawn.h"

QPawn::QPawn(QGraphicsScene* scene, Color color) : QPiece(scene, color)
{
    this->setImage();
    this->setPixmap(QPixmap(QString::fromUtf8(this->getImage())));
}

std::string QPawn::getName() const
{
    return this->name_;
}

std::string QPawn::getImage() const
{
    return this->image_;
}

int QPawn::getValue() const
{
    return this->value_;
}

void QPawn::setImage()
{
    this->image_ = this->getColor() == Color::White ? ":images/wpawn.png" : ":images/bpawn.png";
}
