#ifndef QCHESSBACKBUTTON_H
#define QCHESSBACKBUTTON_H
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include "Color.h"
#include "QGame.h"
#include "QSavedGameText.h"

class QChessBackButton : public QGraphicsRectItem
{
    std::unique_ptr<QSavedGameText> label_;
public:
    std::unique_ptr<QSavedGameText> & label() {return label_;}
    void label(std::unique_ptr<QSavedGameText> label) {label_ = std::move(label);}

    QChessBackButton();

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // QCHESSBACKBUTTON_H
