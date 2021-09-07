#ifndef QCHESSFORWARDBUTTON_H
#define QCHESSFORWARDBUTTON_H
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include "Color.h"
#include "QGame.h"
#include "QSavedGameText.h"

class QChessForwardButton : public QGraphicsRectItem
{
public:
    std::unique_ptr<QSavedGameText> label;

    QChessForwardButton();

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // QCHESSFORWARDBUTTON_H
