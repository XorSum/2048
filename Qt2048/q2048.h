#ifndef Q2048_H
#define Q2048_H
#include <QObject>

class Q2048 {
private:
    int oldArray[4][4],newArray[4][4];
    void backup();
public:
    Q2048();
    ~Q2048();
    void show();
    void save();
    void rotate();
    void left();
    void right();
    void up();
    void down();
    bool isChanged();
    bool isWin();
    bool isFail();
    void add();
    int* getArray();
};


#endif // Q2048_H
