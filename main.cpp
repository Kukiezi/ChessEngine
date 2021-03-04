#include "boardwindow.h"

#include <QApplication>
#include <QGraphicsView>
#include "BoardRect.h"
#include "Board.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    BoardWindow w;
    w.show();
    return a.exec();
}
