#ifndef QSAVEDGAME_H
#define QSAVEDGAME_H
#include <QGraphicsRectItem>
#include <QSavedGameText.h>

class QSavedGame : public QGraphicsRectItem
{
public:
    std::string path;
    std::string name;
    std::unique_ptr<QSavedGameText> gameLabel;

    QSavedGame(std::map<std::string, std::string> savedGame, std::pair<int, int> pos);
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // QSAVEDGAME_H
