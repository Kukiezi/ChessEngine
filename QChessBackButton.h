#ifndef QCHESSBACKBUTTON_H
#define QCHESSBACKBUTTON_H
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include "Color.h"
#include "QGame.h"
#include "QSavedGameText.h"

class QChessBackButton : public QGraphicsRectItem
{
public:
    std::unique_ptr<QSavedGameText> label;

    QChessBackButton();

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // QCHESSBACKBUTTON_H
