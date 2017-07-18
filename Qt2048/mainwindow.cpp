#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QTime>
#include <QDialog>
#include <QTimerEvent>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    q2048 = new Q2048();
    ui->label->setText(tr("玩耍ing"));
    drawRec();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawRec()
{
    int *num;

    num = q2048->getArray();
    ui->label_0->setText(tr("%1").arg(num[0]));
    ui->label_1->setText(tr("%1").arg(num[1]));
    ui->label_2->setText(tr("%1").arg(num[2]));
    ui->label_3->setText(tr("%1").arg(num[3]));
    ui->label_4->setText(tr("%1").arg(num[4]));
    ui->label_5->setText(tr("%1").arg(num[5]));
    ui->label_6->setText(tr("%1").arg(num[6]));
    ui->label_7->setText(tr("%1").arg(num[7]));
    ui->label_8->setText(tr("%1").arg(num[8]));
    ui->label_9->setText(tr("%1").arg(num[9]));
    ui->label_10->setText(tr("%1").arg(num[10]));
    ui->label_11->setText(tr("%1").arg(num[11]));
    ui->label_12->setText(tr("%1").arg(num[12]));
    ui->label_13->setText(tr("%1").arg(num[13]));
    ui->label_14->setText(tr("%1").arg(num[14]));
    ui->label_15->setText(tr("%1").arg(num[15]));

}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_W :
        on_pushButton_up_clicked();
        break;
    case Qt::Key_A :
        on_pushButton_left_clicked();
        break;
    case Qt::Key_S :
        on_pushButton_down_clicked();
        break;
    case Qt::Key_D :
        on_pushButton_right_clicked();
        break;

    }
}

void MainWindow::on_pushButton_right_clicked()
{
    if (q2048->isWin())
    {
        ui->label->setText(tr("你赢了,其实可以用WASD哦"));
    }
    else if (q2048->isFail())
    {
        ui->label->setText(tr("你输了"));
    }

    q2048->save();
    q2048->right();
    if (q2048->isChanged()) q2048->add();
    drawRec();
}

void MainWindow::on_pushButton_up_clicked()
{
    if (q2048->isWin())
    {
        ui->label->setText(tr("你赢了"));
    }
    else if (q2048->isFail())
    {
        ui->label->setText(tr("你输了"));
    }
    q2048->save();
    q2048->up();
    if (q2048->isChanged()) q2048->add();
    drawRec();
}

void MainWindow::on_pushButton_down_clicked()
{
    if (q2048->isWin())
    {
        ui->label->setText(tr("你赢了"));
    }
    else if (q2048->isFail())
    {
        ui->label->setText(tr("你输了"));
    }
    q2048->save();
    q2048->down();
    if (q2048->isChanged()) q2048->add();
    drawRec();
}

void MainWindow::on_pushButton_left_clicked()
{
    if (q2048->isWin())
    {
        ui->label->setText(tr("你赢了"));
    }
    else if (q2048->isFail())
    {
        ui->label->setText(tr("你输了"));
    }
    q2048->save();
    q2048->left();
    if (q2048->isChanged()) q2048->add();
    drawRec();
}
