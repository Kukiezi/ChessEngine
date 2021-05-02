#include "boardwindow.h"
#include "ui_boardwindow.h"
#include <QApplication>
#include <QGraphicsView>
#include "QBoardSquare.h"
#include "QChessBoard.h"
#include <QTextStream>
#include <QPixmap>
#include <QDir>
#include "QGame.h"
#include "QReplayGame.h"
#include "ChessGraphicsView.h"
#include "Engine/GameType.h"

extern QGame * game;
QGraphicsScene* scene;
ChessGraphicsView* view;

BoardWindow::BoardWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BoardWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    scene->setBackgroundBrush(QColor("#18191A"));
    scene->setSceneRect(0, 0, 1280, 960);

}

void BoardWindow::setupUi()
{
    ui->setupUi(this);
}

BoardWindow::~BoardWindow()
{
    delete ui;
}


void BoardWindow::on_pushButton_clicked()
{
    game->startGame(GameType::NORMAL);
    view = new ChessGraphicsView(scene);
    view->setMinimumSize(1280, 960);
    setCentralWidget(view);
    show();
}

void BoardWindow::on_pushButton_2_clicked()
{
   game->getSavedGamesScreen();

   view = new ChessGraphicsView(scene);
   view->setMinimumSize(1280, 960);
   setCentralWidget(view);
   show();
}

void BoardWindow::on_pushButton_5_clicked()
{
    game->startGame(GameType::AI);

    view = new ChessGraphicsView(scene);
    view->setMinimumSize(1280, 960);
    setCentralWidget(view);
    show();
}

void BoardWindow::on_pushButton_3_clicked()
{
    game->getStartFromPositionScreen();

    view = new ChessGraphicsView(scene);
    view->setMinimumSize(1280, 960);
    setCentralWidget(view);
    show();
}
