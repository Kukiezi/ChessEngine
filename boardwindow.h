#ifndef BOARDWINDOW_H
#define BOARDWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class BoardWindow; }
QT_END_NAMESPACE

class BoardWindow : public QMainWindow
{
    Q_OBJECT

public:
    BoardWindow(QWidget *parent = nullptr);
    ~BoardWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::BoardWindow *ui;
};
#endif // BOARDWINDOW_H
