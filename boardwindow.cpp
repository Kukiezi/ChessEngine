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
#include "ChessGraphicsView.h"

extern QGame * game;

BoardWindow::BoardWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BoardWindow)
{
    ui->setupUi(this);
}

BoardWindow::~BoardWindow()
{
    delete ui;
}


void BoardWindow::on_pushButton_clicked()
{
    hide();
    QGraphicsScene* scene = new QGraphicsScene();
    game->startGame(scene);


//   QString imageFileName = QString::fromUtf8("/Users/dknopik/Code/ChessEngine/queen.png");

//   qInfo() << imageFileName;
//   QImage* imageObject = new QImage(imageFileName);

//   QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(*imageObject));
//   item->setPos(100, 100);

//   scene->addItem(item);

   ChessGraphicsView* view = new ChessGraphicsView(scene);
   view->setSceneRect(scene->sceneRect());
   view->setMinimumSize(1280, 960);
   view->show();
}
