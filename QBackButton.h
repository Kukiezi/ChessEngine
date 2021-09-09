#ifndef QBACKBUTTON_H
#define QBACKBUTTON_H
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include "QGame.h"
#include "QSavedGameText.h"

class QBackButton : public QGraphicsRectItem
{
    std::unique_ptr<QSavedGameText> backLabel_;
public:
    std::unique_ptr<QSavedGameText> & backLabel() {return backLabel_;}
    void backLabel(std::unique_ptr<QSavedGameText> backLabel) {backLabel_ = std::move(backLabel);}
    QBackButton();

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // QBACKBUTTON_H
