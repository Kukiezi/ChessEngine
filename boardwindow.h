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
    void setupUi();
    ~BoardWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::BoardWindow *ui;
};
#endif // BOARDWINDOW_H
