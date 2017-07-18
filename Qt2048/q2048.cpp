#include "q2048.h"
#include <QTime>
#include "mainwindow.h"
#include "ui_mainwindow.h"

Q2048::Q2048() {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            oldArray[i][j] = 0;
            newArray[i][j] = 0;
        }
    qsrand((QTime(0,0,0,0).secsTo(QTime::currentTime())));
    int x = qrand()%4, y = qrand()%4;
    newArray[x][y] = (rand()%2+1)*2;
}



Q2048::~Q2048() {

}

void Q2048::rotate() {
    int i,j,tmpArray[4][4];
    for (i=0;i<4;i++){
        for (j=0;j<4;j++){
            tmpArray[i][j]=newArray[3-j][i];
        }
    }
    for (i=0;i<4;i++){
        for (j=0;j<4;j++){
            newArray[i][j]=tmpArray[i][j];
        }
    }

}

void Q2048::left() {
    int i, j, k;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            if (newArray[i][j] == 0) {
                for (k = j + 1; k < 4; k++)
                    if (newArray[i][k] != 0) {
                        newArray[i][j] = newArray[i][k];
                        newArray[i][k] = 0;
                        break;
                    }
            }
        }
        for (j = 0; j < 3; j++) {
            if (newArray[i][j] == newArray[i][j + 1]) {
                newArray[i][j] = newArray[i][j] * 2;
                newArray[i][j + 1] = 0;
            }
        }
        for (j = 0; j < 3; j++) {
            if (newArray[i][j] == 0) {
                for (k = j + 1; k < 4; k++) {
                    if (newArray[i][k] != 0) {
                        newArray[i][j] = newArray[i][k];
                        newArray[i][k] = 0;
                        break;
                    }
                }
            }
        }
    }
}
void Q2048::right() {
    rotate();
    rotate();
    left();
    rotate();
    rotate();
}

void Q2048::up() {
    rotate();
    rotate();
    rotate();
    left();
    rotate();
}

void Q2048::down() {
    rotate();
    left();
    rotate();
    rotate();
    rotate();
}



bool Q2048::isChanged() {
    bool flag=1;
    for (int i=0;i<4&&flag;i++)
        for (int j=0;j<4&&flag;j++)
            if (oldArray[i][j]!=newArray[i][j])
                flag= false;
    return !flag;
}

void Q2048::add() {
    int x=qrand()%4,y=qrand()%4;
    while(newArray[x][y])
    {
        x=qrand()%4;
        y=qrand()%4;
    }
    newArray[x][y]=(qrand()%2+1)*2;
}



int* Q2048::getArray()
{
    return &(newArray[0][0]);
}

void Q2048::save()
{
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++)
            oldArray[i][j]=newArray[i][j];
}

bool Q2048::isWin()
{
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++)
            if (newArray[i][j]==2048) return true;
    return false;
}
bool Q2048::isFail()
{
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++)
            if (newArray[i][j]==0) return false;

    for (int i=0;i<3;i++)
        for (int j=0;j<4;j++)
            if (newArray[i][j]==newArray[i+1][j]) return false;
    for (int i=0;i<4;i++)
        for (int j=0;j<3;j++)
            if (newArray[i][j]==newArray[i][j+1]) return false;
    return true;

}
