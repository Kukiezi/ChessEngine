#ifndef QCHESSFORWARDBUTTON_H
#define QCHESSFORWARDBUTTON_H
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include "Color.h"
#include "QGame.h"
#include "QSavedGameText.h"

class QChessForwardButton : public QGraphicsRectItem
{
    std::unique_ptr<QSavedGameText> label_;
public:
    std::unique_ptr<QSavedGameText> & label() {return label_;}
    void label(std::unique_ptr<QSavedGameText> label) {label_ = std::move(label);}

    QChessForwardButton();

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // QCHESSFORWARDBUTTON_H
