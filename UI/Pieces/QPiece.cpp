#include "QPiece.h"
#include "QMove.h"
#include "QBoardSquare.h"
#include <QGraphicsSceneDragDropEvent>
#include "QGame.h"

extern QGame * game;

extern Engine * engine;

QPiece::QPiece(Color _color)
{
    setColor(_color);
    dragged_ = false;
    if (game->getGameType() != GameType::REPLAY) {
        setFlag(QGraphicsPixmapItem::ItemIsMovable);
        setFlag(QGraphicsPixmapItem::ItemSendsGeometryChanges);
    }

    move = new QMove();
}

void QPiece::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (game->getGameType() == GameType::REPLAY) {
        return;
    }

    QList<QGraphicsItem*> colItems = collidingItems();
    auto rect = dynamic_cast<QBoardSquare*>(colItems[0]);
    move->from = rect;
    from = std::make_pair(rect->row, rect->col);
}

void QPiece::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (game->getGameType() == GameType::REPLAY) {
        return;
    }

    this->dragged_ = true;
    this->setZValue(10);
    QGraphicsPixmapItem::mouseMoveEvent(event);
}

void QPiece::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    extern QGraphicsScene * scene;
    if (game->getGameType() == GameType::REPLAY) {
        return;
    }
//    if (engine->isGameOver()) {
//        game->getTurn()->setTurn(GAME_OVER);
//        return;
//    }
    if (this->dragged_) {
        QList<QGraphicsItem*> colItems = collidingItems();
        if (colItems.isEmpty()) {
            this->setPos(this->anchorPoint);
        } else {
            QGraphicsItem* closestItem = colItems.at(0);
            qreal shortestDist = 100000;
            foreach(QGraphicsItem* item, colItems){
                if (item->type() == 7) {
                    continue;
                }
                QLineF line(item->sceneBoundingRect().center(),
                            this->sceneBoundingRect().center());
                if(line.length() < shortestDist){
                    shortestDist = line.length();
                    closestItem = item;
                }
            }
            this->setPos(closestItem->scenePos());
            QBoardSquare* boardRect = dynamic_cast<QBoardSquare*>(closestItem);

            if (boardRect) {
                this->to = std::make_pair(boardRect->row, boardRect->col);
                if (!engine->makeMove(this->from, this->to)) {
                    this->setPos(this->anchorPoint);
                } else {
                    move->to = boardRect;
                    boardRect->setPiece(this);
                    move->from->removePiece();
                    std::cout << this->getColor() << std::endl;
                    std::cout << boardRect->row << std::endl;
                    std::cout << this->getName() << std::endl;

                    // Transform pawn to queen if reached the other side of the board
                    if (this->getColor() == Color::White && boardRect->row == 7 && this->getName() == "Pawn") {
                        QPiece* pieceToAdd = new QQueen(Color::White);
                        boardRect->setPiece(pieceToAdd);
                        scene->addItem(pieceToAdd);
                    }
                    if (this->getColor() == Color::Black && boardRect->row == 0 && this->getName() == "Pawn") {
                        QPiece* pieceToAdd = new QQueen(Color::Black);
                        boardRect->setPiece(pieceToAdd);
                        scene->addItem(pieceToAdd);
                    }

                    game->getTurn()->setTurn(engine->getTurn());
                    game->resetSquareColors();
                    move->from->setColor(Color::MOVE_FROM);
                    move->to->setColor(Color::MOVE_TO);
                    auto castleMove = engine->getGame()->getLastCastleMove();
                    if (castleMove != NULL) {
                        auto pieceToCastle = game->getChessBoard()->boardSquares[castleMove->castleFrom.first][castleMove->castleFrom.second]->getPiece();
                        game->getChessBoard()->boardSquares[castleMove->castleTo.first][castleMove->castleTo.second]->setPiece(pieceToCastle);
                        game->getChessBoard()->boardSquares[castleMove->castleFrom.first][castleMove->castleFrom.second]->removePiece();
                    }
                    if (game->getGameType() == GameType::AI) {
                        auto aiMove = engine->getAIMove();
                        if (aiMove != NULL) {
                            auto aiPiece = game->getChessBoard()->boardSquares[aiMove->from.first][aiMove->from.second]->getPiece();
                            aiPiece->setZValue(10);
                            game->getChessBoard()->boardSquares[aiMove->to.first][aiMove->to.second]->setPiece(aiPiece);
                            game->getChessBoard()->boardSquares[aiMove->from.first][aiMove->from.second]->removePiece();
                            game->getTurn()->setTurn(engine->getTurn());
                            game->resetSquareColors();
                            game->getChessBoard()->boardSquares[aiMove->to.first][aiMove->to.second]->setColor(Color::MOVE_TO);
                            game->getChessBoard()->boardSquares[aiMove->from.first][aiMove->from.second]->setColor(Color::MOVE_FROM);
                        }
                    }
                }
            } else {
                this->setPos(this->anchorPoint);
            }

        }
        this->dragged_ = false;
    }
    this->setZValue(1);
    QGraphicsPixmapItem::mouseReleaseEvent(event);
}

std::string QPiece::getName() const
{
    return this->name_;
}

std::string QPiece::getImage() const
{
    return this->image_;
}

int QPiece::getValue() const
{
    return this->value_;
}

Color QPiece::getColor()
{
    return this->color_;
}

void QPiece::setAnchorPoint(const QPoint &anchorPoint)
{
    this->anchorPoint = anchorPoint;
}

void QPiece::setColor(Color color)
{
    color_ = color;
}

QGraphicsScene *QPiece::getScene()
{
    return this->scene_;
}

void QPiece::setImage()
{

}

void QPiece::print()
{
    std::cout << getName() << " " << getValue() << " " << getColorText() << std::endl;
}

std::string QPiece::getColorText()
{
    if (getColor() == Color::White) {
        return "White";
    }
    return "Black";
}

