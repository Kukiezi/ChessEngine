#include "boardwindow.h"

#include <QApplication>
#include <QGraphicsView>
#include "QBoardSquare.h"
#include "QChessBoard.h"
#include "Engine/Engine.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Engine* engine = new Engine();
//    engine->startGame();
//    std::unique_ptr<Engine> engine(new Engine());
//    engine->startGame();
//    engine->getGame()->printChessBoard();
//    engine->makeMove("e2e4");
//    engine->getGame()->printChessBoard();
//    engine->makeMove("a7a5");
//    engine->getGame()->printChessBoard();
//    engine->makeMove("e1e2");
//    engine->getGame()->printChessBoard();
//    engine->makeMove("a5a4");
//    engine->getGame()->printChessBoard();
//    engine->makeMove("e2e3");
//    engine->getGame()->printChessBoard();

//    engine->makeMove("e4d5");
//    engine->getGame()->printChessBoard();

    BoardWindow w;
    w.show();
    return a.exec();
}
