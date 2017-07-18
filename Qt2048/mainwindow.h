#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QObject>
#include <QPushButton>
#include <QDialog>
#include <QLabel>
#include "q2048.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_pushButton_right_clicked();

    void on_pushButton_up_clicked();

    void on_pushButton_down_clicked();

    void on_pushButton_left_clicked();

private:
    Ui::MainWindow *ui;
    Q2048 *q2048;
    void drawRec();
protected:
    void keyPressEvent (QKeyEvent*);

};

#endif // MAINWINDOW_H
