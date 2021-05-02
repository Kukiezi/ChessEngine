#ifndef QCHESSBACKBUTTON_H
#define QCHESSBACKBUTTON_H
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include "Color.h"
#include "QGame.h"

class QChessBackButton : public QGraphicsRectItem
{
public:
    QChessBackButton();

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // QCHESSBACKBUTTON_H
