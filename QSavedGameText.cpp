#include "QSavedGameText.h"

QSavedGameText::QSavedGameText(std::string text, std::pair<int, int> pos, QGraphicsItem* parent) : QGraphicsTextItem(parent)
{
    setPlainText(QString::fromUtf8(text));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times", 16));
    setPos(pos.first, pos.second);
}
