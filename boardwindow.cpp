#include "boardwindow.h"
#include "ui_boardwindow.h"
#include <QApplication>
#include <QGraphicsView>
#include "BoardRect.h"
#include "Board.h"
#include <QTextStream>
#include <QPixmap>
#include <QDir>
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

    Board* board = new Board();

    for (auto rect : board->boardRects) {
        scene->addItem(rect);
        scene->addItem(rect->piece);
    }

//   QString imageFileName = QString::fromUtf8("/Users/dknopik/Code/ChessEngine/queen.png");

//   qInfo() << imageFileName;
//   QImage* imageObject = new QImage(imageFileName);

//   QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(*imageObject));
//   item->setPos(100, 100);

//   scene->addItem(item);

   QGraphicsView* view = new QGraphicsView(scene);

   view->show();

}
