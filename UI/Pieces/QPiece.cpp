#include "QPiece.h"
#include <QString>
#include <QGraphicsSceneDragDropEvent>
#include "QBoardSquare.h"

QPiece::QPiece(QGraphicsScene* scene, Color _color)
{
    setColor(_color);
    setFlag(QGraphicsPixmapItem::ItemIsMovable);
    setFlag(QGraphicsPixmapItem::ItemSendsGeometryChanges);
    dragged_ = false;
    this->setScene(scene);
}

void QPiece::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QList<QGraphicsItem*> colItems = collidingItems();
    qInfo()<< colItems;
//    this->rect = dynamic_cast<BoardRect*>(colItems[0]);
}

void QPiece::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    qInfo()<< "MOVE EVENT";
    this->dragged_ = true;
    this->setZValue(10);
    QGraphicsPixmapItem::mouseMoveEvent(event);
}

void QPiece::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (this->dragged_) {
        QList<QGraphicsItem*> colItems = collidingItems();
        if (colItems.isEmpty()) {
            this->setPos(this->anchorPoint);
        } else {
            QGraphicsItem* closestItem = colItems.at(0);
            qreal shortestDist = 100000;
            foreach(QGraphicsItem* item, colItems){
                if (item->type() == 7) {
                    continue;
                }
                QLineF line(item->sceneBoundingRect().center(),
                            this->sceneBoundingRect().center());
                if(line.length() < shortestDist){
                    shortestDist = line.length();
                    closestItem = item;
                }
            }
            qInfo()<< closestItem->type();
            this->setPos(closestItem->scenePos());
            QBoardSquare* boardRect = dynamic_cast<QBoardSquare*>(closestItem);
            qInfo()<< this;
            boardRect->setPiece(this);
        }
        this->dragged_ = false;
    }
    this->setZValue(1);
    QGraphicsPixmapItem::mouseReleaseEvent(event);
}

std::string QPiece::getName() const
{
    return this->name_;
}

std::string QPiece::getImage() const
{
    return this->image_;
}

int QPiece::getValue() const
{
    return this->value_;
}

Color QPiece::getColor()
{
    return this->color_;
}

void QPiece::setAnchorPoint(const QPoint &anchorPoint)
{
    this->anchorPoint = anchorPoint;
}

void QPiece::setColor(Color color)
{
    color_ = color;
}

void QPiece::setScene(QGraphicsScene *scene)
{
    this->scene_ = scene;
}

QGraphicsScene *QPiece::getScene()
{
    return this->scene_;
}

void QPiece::setImage()
{

}

void QPiece::print()
{
    std::cout << getName() << " " << getValue() << " " << getColorText() << std::endl;
}

std::string QPiece::getColorText()
{
    if (getColor() == Color::White) {
        return "White";
    }
    return "Black";
}

