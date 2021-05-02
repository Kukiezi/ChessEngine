#pragma once

#include <iostream>
#include <string>
#include <QGraphicsPixmapItem>
#include <QPoint>
#include "../../Color.h"
#include "QEngine.h"

class QPiece : public QGraphicsPixmapItem
{
    std::string name_;
    int value_;
    Color color_;
    std::string image_;
    QGraphicsScene* scene_;
    std::pair<int, int> from;
    std::pair<int, int> to;

public:
    QPoint anchorPoint;
    bool dragged_;
    class QMove* move;

    QPiece(Color _color);

    virtual std::string getName() const;
    virtual std::string getImage() const;
    virtual int getValue() const;
    Color getColor();

    void setAnchorPoint(const QPoint& anchorPoint);
    void setColor(Color color);
    QGraphicsScene* getScene();
    virtual void setImage();
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    void print();

    std::string getColorText();
};

