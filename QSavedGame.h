#ifndef QSAVEDGAME_H
#define QSAVEDGAME_H
#include <QGraphicsRectItem>
#include <QSavedGameText.h>

class QSavedGame : public QGraphicsRectItem
{
    std::string path_;
    std::string name_;
    std::unique_ptr<QSavedGameText> gameLabel_;
public:
    std::unique_ptr<QSavedGameText> & gameLabel() {return gameLabel_;}
    void gameLabel(std::unique_ptr<QSavedGameText> gameLabel) {gameLabel_ = std::move(gameLabel);}

    const std::string path() const {return path_;}
    void path(const std::string path) {path_ = path;}

    const std::string name() const {return name_;}
    void name(const std::string name) {name_ = name;}

    QSavedGame(std::map<std::string, std::string> savedGame, std::pair<int, int> pos);
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // QSAVEDGAME_H
