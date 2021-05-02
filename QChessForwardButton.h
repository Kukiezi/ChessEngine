#ifndef QCHESSFORWARDBUTTON_H
#define QCHESSFORWARDBUTTON_H
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include "Color.h"
#include "QGame.h"

class QChessForwardButton : public QGraphicsRectItem
{
public:
    QChessForwardButton();

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // QCHESSFORWARDBUTTON_H
