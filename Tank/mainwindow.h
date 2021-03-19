#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define WIWIDTH 1014
#define WIHEIGHT 1014
#define SWIDTH 38
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3
#define BRICK 0
#define IRON 1
#define GRASS 2
#define WATER 3
#define EMPTY 4
#define HOME 5
#define PLAYER 1
#define BULLET 2
#include <QMainWindow>
#include<vector>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
struct bullet
{
    int posx,posy,direction,form;
};
struct explose
{
    int x,y,idx=0;
};

class Tank
{
public:
    int posx,posy,idex,health,attacking=0,type,moving=0,start=4;
    QPixmap direction[4];
    bool ingrass=0;
    Tank();
    Tank(int x,int y,int index);
    Tank(int ty);
    ~Tank();
    void emove();
    void shoot();

};


bool block(int x,int y);
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);
    void picini();
    void timerEvent(QTimerEvent *event);
    void keyPressEvent(QKeyEvent *event);
private:
    int eventID1,eventIDbull,CD,MOVING,ENEMYMOVE,enemynumber=7,enemyleft=10,POWER,EXPLOSE;
    int test=0;
    std::vector<Tank> eTank;
    std::vector<explose> exp;
    int GAME=1;
    Tank player;
    Ui::MainWindow *ui;
    QPixmap backg,gameover,ground[5],bulletpic[4],summon[4],explosion[4],winpic;
};
#endif // MAINWINDOW_H
