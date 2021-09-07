#ifndef QSAVEDGAMETEXT_H
#define QSAVEDGAMETEXT_H
#include <QGraphicsTextItem>
#include "Color.h"
#include <QFont>

class QSavedGameText: public QGraphicsTextItem
{
public:
    QSavedGameText(std::string text, std::pair<int, int> pos, bool darkColor = false, QGraphicsItem* parent = 0);
    void setTurn(Color turn);
    std::string getTurn();
};

#endif // QSAVEDGAMETEXT_H
