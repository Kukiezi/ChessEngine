#include "QSavedGameText.h"

QSavedGameText::QSavedGameText(std::string text, std::pair<int, int> pos, bool darkColor, QGraphicsItem* parent) : QGraphicsTextItem(parent)
{
    setPlainText(QString::fromUtf8(text));
    setDefaultTextColor(!darkColor ? Qt::white : Qt::black);
    setFont(QFont("times", 16));
    setPos(pos.first, pos.second);
}
