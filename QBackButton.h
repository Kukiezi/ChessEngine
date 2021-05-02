#ifndef QBACKBUTTON_H
#define QBACKBUTTON_H
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include "QGame.h"
#include "QSavedGameText.h"

class QBackButton : public QGraphicsRectItem
{
public:
    std::unique_ptr<QSavedGameText> backLabel;

    QBackButton();

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // QBACKBUTTON_H
