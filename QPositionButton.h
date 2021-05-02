#ifndef QPOSITIONBUTTON_H
#define QPOSITIONBUTTON_H
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include "QSavedGameText.h"
#include "QPositionInput.h"

class QPositionButton: public QGraphicsRectItem
{
public:
    QPositionInput* input;
    std::unique_ptr<QSavedGameText> backLabel;
    QPositionButton(QPositionInput* input);

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // QPOSITIONBUTTON_H
