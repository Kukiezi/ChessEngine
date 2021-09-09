#ifndef QPOSITIONBUTTON_H
#define QPOSITIONBUTTON_H
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include "QSavedGameText.h"
#include "QPositionInput.h"

class QPositionButton: public QGraphicsRectItem
{
    QPositionInput* input_;
    std::unique_ptr<QSavedGameText> label_;
public:
    QPositionInput* input() {return input_;}
    void input(QPositionInput* input) {input_ = input;}
    std::unique_ptr<QSavedGameText> & label() {return label_;}
    void label(std::unique_ptr<QSavedGameText> label) {label_ = std::move(label);}

    QPositionButton(QPositionInput* input);

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // QPOSITIONBUTTON_H
