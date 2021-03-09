#ifndef QPIECE_H
#define QPIECE_H
#include <iostream>
#include <string>
#include <QGraphicsPixmapItem>
#include <QPoint>
#include "../../Color.h"
//#include "../Board.h"

class QPiece : public QGraphicsPixmapItem
{
    std::string name_;
    int value_;
    Color color_;
    std::string image_;
    QGraphicsScene* scene_;

public:
    QPoint anchorPoint;
//    BoardRect* rect;
    bool dragged_;

    QPiece(QGraphicsScene* scene, Color _color);

    virtual std::string getName() const;
    virtual std::string getImage() const;
    virtual int getValue() const;
    Color getColor();

    void setAnchorPoint(const QPoint& anchorPoint);
    void setColor(Color color);
    void setScene(QGraphicsScene* scene);
    QGraphicsScene* getScene();
    virtual void setImage();
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    void print();

    std::string getColorText();
};

#endif // QPIECE_H
