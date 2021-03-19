#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include<ctime>
#include<cstdlib>
#include<QKeyEvent>
#include<fstream>
int mmap[26][26];
std::vector<bullet> allbullet;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player=Tank(0) ;
    picini();
    eventID1=startTimer(1);
    eventIDbull=startTimer(50);
    ENEMYMOVE=startTimer(500);
    POWER=startTimer(125);
    srand(time(0));
    int x,index;
    for (int i=0;i<enemyleft;i++)
    {
       x=rand()%26;
       index=rand()%4;
       Tank a(x,0,index);
       eTank.push_back(a);
    }
    EXPLOSE=startTimer(250);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void mmapini()
{
    mmap[0][0]=4;
    mmap[1][0]=4;
    mmap[2][0]=4;
    mmap[3][0]=4;
    mmap[4][0]=4;
    mmap[5][0]=4;
    mmap[6][0]=4;
    mmap[7][0]=4;
    mmap[8][0]=4;
    mmap[9][0]=4;
    mmap[10][0]=4;
    mmap[11][0]=4;
    mmap[12][0]=4;
    mmap[13][0]=4;
    mmap[14][0]=4;
    mmap[15][0]=4;
    mmap[16][0]=4;
    mmap[17][0]=4;
    mmap[18][0]=4;
    mmap[19][0]=4;
    mmap[20][0]=4;
    mmap[21][0]=4;
    mmap[22][0]=4;
    mmap[23][0]=4;
    mmap[24][0]=4;
    mmap[25][0]=4;
    mmap[0][1]=0;
    mmap[1][1]=4;
    mmap[2][1]=4;
    mmap[3][1]=0;
    mmap[4][1]=0;
    mmap[5][1]=4;
    mmap[6][1]=4;
    mmap[7][1]=4;
    mmap[8][1]=0;
    mmap[9][1]=3;
    mmap[10][1]=3;
    mmap[11][1]=3;
    mmap[12][1]=3;
    mmap[13][1]=3;
    mmap[14][1]=3;
    mmap[15][1]=3;
    mmap[16][1]=0;
    mmap[17][1]=4;
    mmap[18][1]=4;
    mmap[19][1]=4;
    mmap[20][1]=4;
    mmap[21][1]=0;
    mmap[22][1]=0;
    mmap[23][1]=4;
    mmap[24][1]=4;
    mmap[25][1]=0;
    mmap[0][2]=0;
    mmap[1][2]=4;
    mmap[2][2]=4;
    mmap[3][2]=0;
    mmap[4][2]=0;
    mmap[5][2]=4;
    mmap[6][2]=4;
    mmap[7][2]=4;
    mmap[8][2]=4;
    mmap[9][2]=0;
    mmap[10][2]=4;
    mmap[11][2]=4;
    mmap[12][2]=3;
    mmap[13][2]=4;
    mmap[14][2]=4;
    mmap[15][2]=0;
    mmap[16][2]=4;
    mmap[17][2]=4;
    mmap[18][2]=4;
    mmap[19][2]=4;
    mmap[20][2]=4;
    mmap[21][2]=0;
    mmap[22][2]=0;
    mmap[23][2]=4;
    mmap[24][2]=4;
    mmap[25][2]=0;
    mmap[0][3]=0;
    mmap[1][3]=4;
    mmap[2][3]=4;
    mmap[3][3]=4;
    mmap[4][3]=4;
    mmap[5][3]=4;
    mmap[6][3]=3;
    mmap[7][3]=4;
    mmap[8][3]=4;
    mmap[9][3]=4;
    mmap[10][3]=0;
    mmap[11][3]=2;
    mmap[12][3]=2;
    mmap[13][3]=2;
    mmap[14][3]=0;
    mmap[15][3]=4;
    mmap[16][3]=4;
    mmap[17][3]=4;
    mmap[18][3]=3;
    mmap[19][3]=4;
    mmap[20][3]=4;
    mmap[21][3]=4;
    mmap[22][3]=4;
    mmap[23][3]=4;
    mmap[24][3]=4;
    mmap[25][3]=0;
    mmap[0][4]=0;
    mmap[1][4]=2;
    mmap[2][4]=2;
    mmap[3][4]=2;
    mmap[4][4]=2;
    mmap[5][4]=4;
    mmap[6][4]=4;
    mmap[7][4]=0;
    mmap[8][4]=4;
    mmap[9][4]=0;
    mmap[10][4]=4;
    mmap[11][4]=0;
    mmap[12][4]=2;
    mmap[13][4]=0;
    mmap[14][4]=4;
    mmap[15][4]=0;
    mmap[16][4]=4;
    mmap[17][4]=0;
    mmap[18][4]=4;
    mmap[19][4]=4;
    mmap[20][4]=4;
    mmap[21][4]=2;
    mmap[22][4]=2;
    mmap[23][4]=2;
    mmap[24][4]=2;
    mmap[25][4]=0;
    mmap[0][5]=0;
    mmap[1][5]=2;
    mmap[2][5]=2;
    mmap[3][5]=2;
    mmap[4][5]=2;
    mmap[5][5]=0;
    mmap[6][5]=4;
    mmap[7][5]=4;
    mmap[8][5]=4;
    mmap[9][5]=4;
    mmap[10][5]=4;
    mmap[11][5]=2;
    mmap[12][5]=0;
    mmap[13][5]=2;
    mmap[14][5]=4;
    mmap[15][5]=4;
    mmap[16][5]=4;
    mmap[17][5]=4;
    mmap[18][5]=4;
    mmap[19][5]=4;
    mmap[20][5]=0;
    mmap[21][5]=2;
    mmap[22][5]=2;
    mmap[23][5]=2;
    mmap[24][5]=2;
    mmap[25][5]=0;
    mmap[0][6]=0;
    mmap[1][6]=2;
    mmap[2][6]=2;
    mmap[3][6]=2;
    mmap[4][6]=2;
    mmap[5][6]=0;
    mmap[6][6]=4;
    mmap[7][6]=0;
    mmap[8][6]=4;
    mmap[9][6]=4;
    mmap[10][6]=4;
    mmap[11][6]=0;
    mmap[12][6]=2;
    mmap[13][6]=0;
    mmap[14][6]=4;
    mmap[15][6]=4;
    mmap[16][6]=4;
    mmap[17][6]=4;
    mmap[18][6]=4;
    mmap[19][6]=4;
    mmap[20][6]=0;
    mmap[21][6]=2;
    mmap[22][6]=2;
    mmap[23][6]=2;
    mmap[24][6]=2;
    mmap[25][6]=0;
    mmap[0][7]=0;
    mmap[1][7]=4;
    mmap[2][7]=4;
    mmap[3][7]=4;
    mmap[4][7]=4;
    mmap[5][7]=0;
    mmap[6][7]=4;
    mmap[7][7]=4;
    mmap[8][7]=4;
    mmap[9][7]=4;
    mmap[10][7]=0;
    mmap[11][7]=2;
    mmap[12][7]=2;
    mmap[13][7]=2;
    mmap[14][7]=0;
    mmap[15][7]=4;
    mmap[16][7]=4;
    mmap[17][7]=4;
    mmap[18][7]=4;
    mmap[19][7]=4;
    mmap[20][7]=0;
    mmap[21][7]=4;
    mmap[22][7]=4;
    mmap[23][7]=4;
    mmap[24][7]=4;
    mmap[25][7]=0;
    mmap[0][8]=4;
    mmap[1][8]=4;
    mmap[2][8]=4;
    mmap[3][8]=0;
    mmap[4][8]=0;
    mmap[5][8]=0;
    mmap[6][8]=4;
    mmap[7][8]=0;
    mmap[8][8]=4;
    mmap[9][8]=0;
    mmap[10][8]=4;
    mmap[11][8]=4;
    mmap[12][8]=4;
    mmap[13][8]=4;
    mmap[14][8]=4;
    mmap[15][8]=0;
    mmap[16][8]=4;
    mmap[17][8]=4;
    mmap[18][8]=4;
    mmap[19][8]=4;
    mmap[20][8]=0;
    mmap[21][8]=0;
    mmap[22][8]=0;
    mmap[23][8]=4;
    mmap[24][8]=4;
    mmap[25][8]=4;
    mmap[0][9]=4;
    mmap[1][9]=4;
    mmap[2][9]=1;
    mmap[3][9]=1;
    mmap[4][9]=4;
    mmap[5][9]=4;
    mmap[6][9]=4;
    mmap[7][9]=4;
    mmap[8][9]=0;
    mmap[9][9]=4;
    mmap[10][9]=4;
    mmap[11][9]=4;
    mmap[12][9]=4;
    mmap[13][9]=4;
    mmap[14][9]=4;
    mmap[15][9]=4;
    mmap[16][9]=0;
    mmap[17][9]=4;
    mmap[18][9]=4;
    mmap[19][9]=4;
    mmap[20][9]=4;
    mmap[21][9]=4;
    mmap[22][9]=1;
    mmap[23][9]=1;
    mmap[24][9]=4;
    mmap[25][9]=4;
    mmap[0][10]=4;
    mmap[1][10]=4;
    mmap[2][10]=1;
    mmap[3][10]=1;
    mmap[4][10]=4;
    mmap[5][10]=4;
    mmap[6][10]=4;
    mmap[7][10]=0;
    mmap[8][10]=4;
    mmap[9][10]=4;
    mmap[10][10]=4;
    mmap[11][10]=4;
    mmap[12][10]=4;
    mmap[13][10]=4;
    mmap[14][10]=4;
    mmap[15][10]=4;
    mmap[16][10]=4;
    mmap[17][10]=0;
    mmap[18][10]=4;
    mmap[19][10]=4;
    mmap[20][10]=4;
    mmap[21][10]=4;
    mmap[22][10]=1;
    mmap[23][10]=1;
    mmap[24][10]=4;
    mmap[25][10]=4;
    mmap[0][11]=4;
    mmap[1][11]=4;
    mmap[2][11]=1;
    mmap[3][11]=1;
    mmap[4][11]=4;
    mmap[5][11]=4;
    mmap[6][11]=2;
    mmap[7][11]=2;
    mmap[8][11]=2;
    mmap[9][11]=2;
    mmap[10][11]=2;
    mmap[11][11]=2;
    mmap[12][11]=2;
    mmap[13][11]=2;
    mmap[14][11]=2;
    mmap[15][11]=2;
    mmap[16][11]=2;
    mmap[17][11]=2;
    mmap[18][11]=2;
    mmap[19][11]=4;
    mmap[20][11]=4;
    mmap[21][11]=4;
    mmap[22][11]=1;
    mmap[23][11]=1;
    mmap[24][11]=4;
    mmap[25][11]=4;
    mmap[0][12]=4;
    mmap[1][12]=4;
    mmap[2][12]=4;
    mmap[3][12]=4;
    mmap[4][12]=4;
    mmap[5][12]=4;
    mmap[6][12]=2;
    mmap[7][12]=2;
    mmap[8][12]=3;
    mmap[9][12]=3;
    mmap[10][12]=3;
    mmap[11][12]=3;
    mmap[12][12]=3;
    mmap[13][12]=3;
    mmap[14][12]=3;
    mmap[15][12]=3;
    mmap[16][12]=3;
    mmap[17][12]=2;
    mmap[18][12]=2;
    mmap[19][12]=4;
    mmap[20][12]=4;
    mmap[21][12]=4;
    mmap[22][12]=4;
    mmap[23][12]=4;
    mmap[24][12]=4;
    mmap[25][12]=4;
    mmap[0][13]=4;
    mmap[1][13]=0;
    mmap[2][13]=4;
    mmap[3][13]=4;
    mmap[4][13]=0;
    mmap[5][13]=4;
    mmap[6][13]=2;
    mmap[7][13]=2;
    mmap[8][13]=2;
    mmap[9][13]=4;
    mmap[10][13]=4;
    mmap[11][13]=2;
    mmap[12][13]=2;
    mmap[13][13]=2;
    mmap[14][13]=4;
    mmap[15][13]=4;
    mmap[16][13]=2;
    mmap[17][13]=2;
    mmap[18][13]=2;
    mmap[19][13]=4;
    mmap[20][13]=4;
    mmap[21][13]=4;
    mmap[22][13]=4;
    mmap[23][13]=4;
    mmap[24][13]=4;
    mmap[25][13]=4;
    mmap[0][14]=4;
    mmap[1][14]=4;
    mmap[2][14]=0;
    mmap[3][14]=4;
    mmap[4][14]=4;
    mmap[5][14]=4;
    mmap[6][14]=4;
    mmap[7][14]=1;
    mmap[8][14]=4;
    mmap[9][14]=4;
    mmap[10][14]=4;
    mmap[11][14]=0;
    mmap[12][14]=0;
    mmap[13][14]=0;
    mmap[14][14]=4;
    mmap[15][14]=4;
    mmap[16][14]=4;
    mmap[17][14]=1;
    mmap[18][14]=4;
    mmap[19][14]=4;
    mmap[20][14]=4;
    mmap[21][14]=4;
    mmap[22][14]=4;
    mmap[23][14]=4;
    mmap[24][14]=4;
    mmap[25][14]=4;
    mmap[0][15]=4;
    mmap[1][15]=4;
    mmap[2][15]=0;
    mmap[3][15]=4;
    mmap[4][15]=0;
    mmap[5][15]=4;
    mmap[6][15]=4;
    mmap[7][15]=1;
    mmap[8][15]=4;
    mmap[9][15]=4;
    mmap[10][15]=4;
    mmap[11][15]=0;
    mmap[12][15]=0;
    mmap[13][15]=0;
    mmap[14][15]=4;
    mmap[15][15]=4;
    mmap[16][15]=4;
    mmap[17][15]=1;
    mmap[18][15]=4;
    mmap[19][15]=4;
    mmap[20][15]=4;
    mmap[21][15]=4;
    mmap[22][15]=0;
    mmap[23][15]=0;
    mmap[24][15]=4;
    mmap[25][15]=4;
    mmap[0][16]=4;
    mmap[1][16]=0;
    mmap[2][16]=4;
    mmap[3][16]=0;
    mmap[4][16]=4;
    mmap[5][16]=1;
    mmap[6][16]=1;
    mmap[7][16]=1;
    mmap[8][16]=1;
    mmap[9][16]=1;
    mmap[10][16]=4;
    mmap[11][16]=4;
    mmap[12][16]=0;
    mmap[13][16]=4;
    mmap[14][16]=4;
    mmap[15][16]=1;
    mmap[16][16]=1;
    mmap[17][16]=1;
    mmap[18][16]=1;
    mmap[19][16]=1;
    mmap[20][16]=0;
    mmap[21][16]=0;
    mmap[22][16]=4;
    mmap[23][16]=0;
    mmap[24][16]=4;
    mmap[25][16]=4;
    mmap[0][17]=4;
    mmap[1][17]=4;
    mmap[2][17]=4;
    mmap[3][17]=4;
    mmap[4][17]=0;
    mmap[5][17]=4;
    mmap[6][17]=4;
    mmap[7][17]=1;
    mmap[8][17]=4;
    mmap[9][17]=4;
    mmap[10][17]=4;
    mmap[11][17]=4;
    mmap[12][17]=0;
    mmap[13][17]=4;
    mmap[14][17]=4;
    mmap[15][17]=4;
    mmap[16][17]=4;
    mmap[17][17]=1;
    mmap[18][17]=4;
    mmap[19][17]=4;
    mmap[20][17]=0;
    mmap[21][17]=4;
    mmap[22][17]=4;
    mmap[23][17]=4;
    mmap[24][17]=0;
    mmap[25][17]=4;
    mmap[0][18]=0;
    mmap[1][18]=0;
    mmap[2][18]=0;
    mmap[3][18]=4;
    mmap[4][18]=4;
    mmap[5][18]=0;
    mmap[6][18]=4;
    mmap[7][18]=1;
    mmap[8][18]=4;
    mmap[9][18]=4;
    mmap[10][18]=4;
    mmap[11][18]=4;
    mmap[12][18]=0;
    mmap[13][18]=4;
    mmap[14][18]=4;
    mmap[15][18]=4;
    mmap[16][18]=4;
    mmap[17][18]=1;
    mmap[18][18]=4;
    mmap[19][18]=4;
    mmap[20][18]=0;
    mmap[21][18]=4;
    mmap[22][18]=4;
    mmap[23][18]=4;
    mmap[24][18]=0;
    mmap[25][18]=4;
    mmap[0][19]=4;
    mmap[1][19]=4;
    mmap[2][19]=0;
    mmap[3][19]=4;
    mmap[4][19]=4;
    mmap[5][19]=0;
    mmap[6][19]=4;
    mmap[7][19]=4;
    mmap[8][19]=4;
    mmap[9][19]=4;
    mmap[10][19]=4;
    mmap[11][19]=4;
    mmap[12][19]=0;
    mmap[13][19]=4;
    mmap[14][19]=4;
    mmap[15][19]=4;
    mmap[16][19]=4;
    mmap[17][19]=4;
    mmap[18][19]=4;
    mmap[19][19]=4;
    mmap[20][19]=4;
    mmap[21][19]=4;
    mmap[22][19]=4;
    mmap[23][19]=4;
    mmap[24][19]=4;
    mmap[25][19]=4;
    mmap[0][20]=0;
    mmap[1][20]=0;
    mmap[2][20]=2;
    mmap[3][20]=2;
    mmap[4][20]=2;
    mmap[5][20]=2;
    mmap[6][20]=2;
    mmap[7][20]=4;
    mmap[8][20]=4;
    mmap[9][20]=4;
    mmap[10][20]=4;
    mmap[11][20]=4;
    mmap[12][20]=0;
    mmap[13][20]=4;
    mmap[14][20]=4;
    mmap[15][20]=4;
    mmap[16][20]=4;
    mmap[17][20]=4;
    mmap[18][20]=2;
    mmap[19][20]=2;
    mmap[20][20]=2;
    mmap[21][20]=2;
    mmap[22][20]=2;
    mmap[23][20]=2;
    mmap[24][20]=0;
    mmap[25][20]=0;
    mmap[0][21]=0;
    mmap[1][21]=0;
    mmap[2][21]=2;
    mmap[3][21]=2;
    mmap[4][21]=2;
    mmap[5][21]=2;
    mmap[6][21]=2;
    mmap[7][21]=2;
    mmap[8][21]=4;
    mmap[9][21]=4;
    mmap[10][21]=4;
    mmap[11][21]=4;
    mmap[12][21]=0;
    mmap[13][21]=4;
    mmap[14][21]=4;
    mmap[15][21]=4;
    mmap[16][21]=4;
    mmap[17][21]=2;
    mmap[18][21]=2;
    mmap[19][21]=2;
    mmap[20][21]=2;
    mmap[21][21]=2;
    mmap[22][21]=2;
    mmap[23][21]=2;
    mmap[24][21]=0;
    mmap[25][21]=0;
    mmap[0][22]=4;
    mmap[1][22]=4;
    mmap[2][22]=4;
    mmap[3][22]=4;
    mmap[4][22]=4;
    mmap[5][22]=4;
    mmap[6][22]=4;
    mmap[7][22]=1;
    mmap[8][22]=1;
    mmap[9][22]=4;
    mmap[10][22]=4;
    mmap[11][22]=0;
    mmap[12][22]=0;
    mmap[13][22]=0;
    mmap[14][22]=4;
    mmap[15][22]=4;
    mmap[16][22]=1;
    mmap[17][22]=1;
    mmap[18][22]=4;
    mmap[19][22]=4;
    mmap[20][22]=4;
    mmap[21][22]=4;
    mmap[22][22]=4;
    mmap[23][22]=4;
    mmap[24][22]=4;
    mmap[25][22]=4;
    mmap[0][23]=4;
    mmap[1][23]=4;
    mmap[2][23]=4;
    mmap[3][23]=0;
    mmap[4][23]=0;
    mmap[5][23]=4;
    mmap[6][23]=4;
    mmap[7][23]=4;
    mmap[8][23]=4;
    mmap[9][23]=1;
    mmap[10][23]=1;
    mmap[11][23]=4;
    mmap[12][23]=0;
    mmap[13][23]=4;
    mmap[14][23]=1;
    mmap[15][23]=1;
    mmap[16][23]=4;
    mmap[17][23]=4;
    mmap[18][23]=4;
    mmap[19][23]=4;
    mmap[20][23]=4;
    mmap[21][23]=0;
    mmap[22][23]=0;
    mmap[23][23]=4;
    mmap[24][23]=4;
    mmap[25][23]=4;
    mmap[0][24]=4;
    mmap[1][24]=4;
    mmap[2][24]=4;
    mmap[3][24]=3;
    mmap[4][24]=3;
    mmap[5][24]=4;
    mmap[6][24]=4;
    mmap[7][24]=4;
    mmap[8][24]=4;
    mmap[9][24]=4;
    mmap[10][24]=4;
    mmap[11][24]=0;
    mmap[12][24]=0;
    mmap[13][24]=0;
    mmap[14][24]=4;
    mmap[15][24]=4;
    mmap[16][24]=4;
    mmap[17][24]=4;
    mmap[18][24]=4;
    mmap[19][24]=4;
    mmap[20][24]=4;
    mmap[21][24]=3;
    mmap[22][24]=3;
    mmap[23][24]=4;
    mmap[24][24]=4;
    mmap[25][24]=4;
    mmap[0][25]=4;
    mmap[1][25]=4;
    mmap[2][25]=4;
    mmap[3][25]=4;
    mmap[4][25]=4;
    mmap[5][25]=4;
    mmap[6][25]=4;
    mmap[7][25]=4;
    mmap[8][25]=4;
    mmap[9][25]=4;
    mmap[10][25]=4;
    mmap[11][25]=0;
    mmap[12][25]=5;
    mmap[13][25]=0;
    mmap[14][25]=4;
    mmap[15][25]=4;
    mmap[16][25]=4;
    mmap[17][25]=4;
    mmap[18][25]=4;
    mmap[19][25]=4;
    mmap[20][25]=4;
    mmap[21][25]=4;
    mmap[22][25]=4;
    mmap[23][25]=4;
    mmap[24][25]=4;
    mmap[25][25]=4;
}
void MainWindow::picini()
{
    mmapini();
    QPixmap pic1(QString(":/new/prefix1/Graphics/BackGround.jpg")),pic2(QString(":/new/prefix1/Graphics/UIGameOver.bmp")),pic3(QString(":/new/prefix1/Graphics/Map.png")),pic4(QString(":/new/prefix1/Graphics/Bullect.bmp")),pic5(QString(":/new/prefix1/Graphics/Born.bmp")),pic6(QString(":/new/prefix1/Graphics/Explode1.bmp")),pic7(QString(":/new/prefix1/Graphics/Explode2.bmp")),pic8(QString(":/new/prefix1/Graphics/win.png"));
    backg=pic1;
    gameover=pic2;
    for (int i=0;i<5;i++)
    {
        QPixmap temp=pic3.copy(i*32,0,32,32);
        ground[i]=temp;
    }
    for (int i=0;i<4;i++)
    {
        QPixmap temp=pic4.copy(i*8,0,8,8);
        bulletpic[i]=temp;
    }
    for (int i=0;i<4;i++)
    {
        QPixmap temp=pic5.copy(i*32,0,32,32);
        summon[i]=temp;
    }
    explosion[0]=pic6;
    explosion[1]=pic7;
    winpic=pic8;
}
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(-10,-10,WIWIDTH+10,WIHEIGHT+10,backg);
    if(GAME==1)
    {

        for(int i=0;i<26;i++)
        {
            for(int j=0;j<26;j++)
            {
                if(mmap[i][j]<4)
                {
                    painter.drawPixmap(i*SWIDTH,j*SWIDTH,SWIDTH,SWIDTH,ground[mmap[i][j]]);
                }
                else if(mmap[i][j]==4)
                {

                }
                else if(mmap[i][j]==5)
                {
                    painter.drawPixmap(i*SWIDTH,j*SWIDTH,SWIDTH,SWIDTH,ground[4]);
                }
                else
                {

                }

            }
        }
           for (int i=0;i<eTank.size();i++)
           {
               if(!eTank[i].ingrass)
               {
                    painter.drawPixmap(SWIDTH*eTank[i].posx,SWIDTH*eTank[i].posy,SWIDTH,SWIDTH,eTank[i].direction[eTank[i].idex]);
               }
               if(eTank[i].start>0)
               {
                   painter.drawPixmap(SWIDTH*eTank[i].posx,SWIDTH*eTank[i].posy,SWIDTH,SWIDTH,summon[5-eTank[i].start]);
               }
           }
           for (int i=0;i<allbullet.size();i++)
           {
               painter.drawPixmap(allbullet[i].posx*SWIDTH+15,allbullet[i].posy*SWIDTH+15,8,8,bulletpic[allbullet[i].direction]);
           }
           if(!player.ingrass)
        {
            painter.drawPixmap(player.posx*SWIDTH,player.posy*SWIDTH,SWIDTH,SWIDTH,player.direction[player.idex]);
        }
           for (int i=0;i<exp.size();i++)
           {
                painter.drawPixmap(SWIDTH*exp[i].x,SWIDTH*exp[i].y,SWIDTH,SWIDTH,explosion[exp[i].idx]);
           }
    }
    else if(GAME==0)
    {
        painter.drawPixmap(WIWIDTH/4,WIHEIGHT/4,WIWIDTH/2,WIHEIGHT/2,gameover);
    }
    else if(GAME==2)
    {
        painter.drawPixmap(0,0,WIWIDTH,WIHEIGHT,winpic);
    }
}
void MainWindow::timerEvent(QTimerEvent *event)
{
    if(event->timerId()==eventID1)
    {
        repaint();
    }
    else if(event->timerId()==eventIDbull)
    {
        for (int i=0;i<allbullet.size();i++)
        {
            int excute=0;
            if(mmap[allbullet[i].posx][allbullet[i].posy]==IRON)
            {
                allbullet.erase(allbullet.begin()+i);
                continue;
            }
            else if(mmap[allbullet[i].posx][allbullet[i].posy]==BRICK)
            {
                mmap[allbullet[i].posx][allbullet[i].posy]=EMPTY;
                allbullet.erase(allbullet.begin()+i);
                continue;
            }
            else if(mmap[allbullet[i].posx][allbullet[i].posy]==HOME)
            {
                GAME=0;
                repaint();
                continue;
            }
            if(allbullet[i].form!=0)
            {
                for (int j=0;j<eTank.size();j++)
                {
                    if(eTank[j].posx==allbullet[i].posx&&eTank[j].posy==allbullet[i].posy)
                    {
                        allbullet.erase(allbullet.begin()+i);
                        excute=1;
                        break;
                    }

                }
            }
            else
            {
                for (int j=0;j<eTank.size();j++)
                {
                    if(eTank[j].posx==allbullet[i].posx&&eTank[j].posy==allbullet[i].posy)
                    {
                        eTank[j].health--;
                        if(eTank[j].health==0)
                        {
                            explose e{eTank[j].posx,eTank[j].posy};
                            exp.push_back(e);
                            eTank.erase(eTank.begin()+j);
                            enemyleft--;
                            if(enemyleft==0)
                            {
                                GAME=2;
                            }
                        }
                        allbullet.erase(allbullet.begin()+i);
                        excute=1;
                        break;
                    }

                }
            }
            if(excute==1)
            {
                continue;
            }
            if(allbullet[i].form==0)
            {
                if(player.posx==allbullet[i].posx&&player.posy==allbullet[i].posy)
                {
                    allbullet.erase(allbullet.begin()+i);
                    excute=1;
                    break;
                }
            }
            else
            {
                if(player.posx==allbullet[i].posx&&player.posy==allbullet[i].posy)
                {
                    player.health--;
                    if(player.health==0)
                    {
                      GAME=0;
                    }
                    allbullet.erase(allbullet.begin()+i);
                    excute=1;
                    break;
                }


            }
            if(excute==1)
            {
                continue;
            }

            if(allbullet[i].direction==0)
            {
                if(allbullet[i].posy-1>=0)
                {
                    if(mmap[allbullet[i].posx][allbullet[i].posy-1]==GRASS||mmap[allbullet[i].posx][allbullet[i].posy-1]==WATER||mmap[allbullet[i].posx][allbullet[i].posy-1]==EMPTY)
                    {
                        allbullet[i].posy-=1;
                    }
                    else if(mmap[allbullet[i].posx][allbullet[i].posy-1]==IRON)
                    {
                        allbullet.erase(allbullet.begin()+i);
                    }
                    else if(mmap[allbullet[i].posx][allbullet[i].posy-1]==BRICK)
                    {
                        mmap[allbullet[i].posx][allbullet[i].posy-1]=EMPTY;
                        allbullet.erase(allbullet.begin()+i);
                    }
                    else if(mmap[allbullet[i].posx][allbullet[i].posy-1]==HOME)
                    {
                        GAME=0;
                        repaint();
                    }
                }
                else
                {
                    allbullet.erase(allbullet.begin()+i);
                }
            }
            else if(allbullet[i].direction==1)
            {
                if(allbullet[i].posx+1<26)
                {
                    if(mmap[allbullet[i].posx+1][allbullet[i].posy]==GRASS||mmap[allbullet[i].posx+1][allbullet[i].posy]==WATER||mmap[allbullet[i].posx+1][allbullet[i].posy]==EMPTY)
                    {
                        allbullet[i].posx+=1;
                    }
                    else if(mmap[allbullet[i].posx+1][allbullet[i].posy]==IRON)
                    {
                        allbullet.erase(allbullet.begin()+i);
                    }
                    else if(mmap[allbullet[i].posx+1][allbullet[i].posy]==BRICK)
                    {
                        mmap[allbullet[i].posx+1][allbullet[i].posy]=EMPTY;
                        allbullet.erase(allbullet.begin()+i);
                    }
                    else if(mmap[allbullet[i].posx+1][allbullet[i].posy]==HOME)
                    {
                        GAME=0;
                        repaint();
                    }
                }
                else
                {
                    allbullet.erase(allbullet.begin()+i);
                }
            }
            else if(allbullet[i].direction==2)
            {
                if(allbullet[i].posy+1<26)
                {
                    if(mmap[allbullet[i].posx][allbullet[i].posy+1]==GRASS||mmap[allbullet[i].posx][allbullet[i].posy+1]==WATER||mmap[allbullet[i].posx][allbullet[i].posy+1]==EMPTY)
                    {
                        allbullet[i].posy+=1;
                    }
                    else if(mmap[allbullet[i].posx][allbullet[i].posy+1]==IRON)
                    {
                        allbullet.erase(allbullet.begin()+i);
                    }
                    else if(mmap[allbullet[i].posx][allbullet[i].posy+1]==BRICK)
                    {
                        mmap[allbullet[i].posx][allbullet[i].posy+1]=EMPTY;
                        allbullet.erase(allbullet.begin()+i);
                    }
                    else if(mmap[allbullet[i].posx][allbullet[i].posy+1]==HOME)
                    {
                        GAME=0;
                        repaint();
                    }
                }
                else
                {
                    allbullet.erase(allbullet.begin()+i);
                }
            }
            else if(allbullet[i].direction==3)
            {
                if(allbullet[i].posx-1>=0)
                {
                    if(mmap[allbullet[i].posx-1][allbullet[i].posy]==GRASS||mmap[allbullet[i].posx-1][allbullet[i].posy]==WATER||mmap[allbullet[i].posx-1][allbullet[i].posy]==EMPTY)
                    {
                        allbullet[i].posx-=1;
                    }
                    else if(mmap[allbullet[i].posx-1][allbullet[i].posy]==IRON)
                    {
                        allbullet.erase(allbullet.begin()+i);
                    }
                    else if(mmap[allbullet[i].posx-1][allbullet[i].posy]==BRICK)
                    {
                        mmap[allbullet[i].posx-1][allbullet[i].posy]=EMPTY;
                        allbullet.erase(allbullet.begin()+i);
                    }
                    else if(mmap[allbullet[i].posx-1][allbullet[i].posy]==HOME)
                    {
                        GAME=0;
                        repaint();
                    }
                }
                else
                {
                    allbullet.erase(allbullet.begin()+i);
                }
            }
            for (int j=i+1;j<allbullet.size();j++)
            {
                if((allbullet[i].posx==allbullet[j].posx&&allbullet[i].posy==allbullet[j].posy)||(allbullet[i].posx==allbullet[j].posx&&(allbullet[i].posy-allbullet[j].posy==1||allbullet[i].posy-allbullet[j].posy==-1)&&((allbullet[j].direction==0&&allbullet[i].direction==2)||(allbullet[j].direction==2&&allbullet[i].direction==0)))||(allbullet[i].posy==allbullet[j].posy&&(allbullet[i].posx-allbullet[j].posx==1||allbullet[i].posx-allbullet[j].posx==-1)&&((allbullet[j].direction==1&&allbullet[i].direction==3)||(allbullet[j].direction==3&&allbullet[i].direction==1))))
                {
                     allbullet.erase(allbullet.begin()+j);
                     allbullet.erase(allbullet.begin()+i);
                     break;
                }
            }
        }


    }
    else if(event->timerId()==CD&&player.attacking==1)
    {
        player.attacking=0;
    }
    else if(event->timerId()==MOVING&&player.moving==1)
    {
        player.moving=0;
    }
    else if(event->timerId()==ENEMYMOVE)
    {
        for (int i=0;i<eTank.size();i++)
        {
            if(eTank[i].start<=0)
            {
                eTank[i].emove();
            }
        }
    }
    else if(event->timerId()==POWER)
    {
        if(player.start>0)
        {
            player.ingrass=!player.ingrass;
            player.start--;
        }
        else if(player.start==0)
        {
            player.ingrass=0;
            player.start--;
        }
        for (int i=0;i<eTank.size();i++)
        {
            if(eTank[i].start>0)
            {
                eTank[i].ingrass=1;
                eTank[i].start--;
            }
            else if(eTank[i].start==0)
            {
                eTank[i].ingrass=0;
                eTank[i].start--;
            }
        }
    }
    else if(event->timerId()==EXPLOSE)
    {
        for (int i=0;i<exp.size();i++)
        {
            exp[i].idx++;
            if(exp[i].idx>1)
            {
                exp.erase(exp.begin()+i);
            }
        }
        repaint();
    }
}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    int input=event->key();
    if(input==Qt::Key_W)
    {
        player.idex=UP;
        if(player.posy-1>=0&&block(player.posx,player.posy-1)&&player.moving==0)
        {
            player.posy-=1;
            player.moving=1;
            MOVING=startTimer(90);
        }
        if(mmap[player.posx][player.posy]==GRASS)
        {
            player.ingrass=1;
        }
        else if(mmap[player.posx][player.posy]==EMPTY)
        {
            player.ingrass=0;
        }
    }
    else if(input==Qt::Key_D)
    {
        player.idex=RIGHT;
        if(player.posx+1<26&&block(player.posx+1,player.posy)&&player.moving==0)
        {
            player.posx+=1;
            player.moving=1;
            MOVING=startTimer(90);
        }
        if(mmap[player.posx][player.posy]==GRASS)
        {
            player.ingrass=1;
        }
        else if(mmap[player.posx][player.posy]==EMPTY)
        {
            player.ingrass=0;
        }
    }
    else if(input==Qt::Key_S)
    {
        player.idex=DOWN;
        if(player.posy+1<26&&block(player.posx,player.posy+1)&&player.moving==0)
        {
            player.posy+=1;
            player.moving=1;
            MOVING=startTimer(90);
        }
        if(mmap[player.posx][player.posy]==GRASS)
        {
            player.ingrass=1;
        }
        else if(mmap[player.posx][player.posy]==EMPTY)
        {
            player.ingrass=0;
        }
    }
    else if(input==Qt::Key_A)
    {
        player.idex=LEFT;

        if(player.posx-1>=0&&block(player.posx-1,player.posy)&&player.moving==0)
        {
            player.posx-=1;
            player.moving=1;
            MOVING=startTimer(90);
        }
        if(mmap[player.posx][player.posy]==GRASS)
        {
            player.ingrass=1;
        }
        else if(mmap[player.posx][player.posy]==EMPTY)
        {
            player.ingrass=0;
        }
    }
    else if(input==Qt::Key_Space&&player.attacking==0)
    {
           player.attacking=1;
           player.shoot();
           CD=startTimer(600);
    }
    repaint();
}
bool block(int x, int y)
{
    if(mmap[x][y]==GRASS||mmap[x][y]==EMPTY)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
Tank::Tank()
{

}
Tank::Tank(int x,int y,int index)
{
    int type=rand()%3+1;
    this->posx=x;
    this->posy=0;
    if(type==1)
    {
        this->type=type;
        this->idex=index;
        this->health=1;
        QPixmap temp(QString(":/new/prefix1/Graphics/Enemys.bmp"));
        for(int i=0;i<4;i++)
        {
            QPixmap temp1=temp.copy(0,i*28,28,28);
            this->direction[i]=temp1;
        }
    }
    else if(type==2)
    {
        this->idex=index;
        this->health=2;
        QPixmap temp(QString(":/new/prefix1/Graphics/Enemys.bmp"));
        for(int i=0;i<4;i++)
        {
            QPixmap temp1=temp.copy(56,i*28,28,28);
            this->direction[i]=temp1;
        }
    }
    else
    {
        this->type=type;
        this->idex=index;
        this->health=3;
        QPixmap temp(QString(":/new/prefix1/Graphics/Enemys.bmp"));
        for(int i=0;i<4;i++)
        {
            QPixmap temp1=temp.copy(6*28,(i+4)*28,28,28);
            this->direction[i]=temp1;
        }
    }
}
Tank::Tank(int ty)
{
    this->type=ty;
    this->posx=10;
    this->posy=25;
    this->idex=0;
    this->health=3;
    QPixmap temp(QString(":/new/prefix1/Graphics/Player2.bmp"));
    for(int i=0;i<4;i++)
    {
        QPixmap temp1=temp.copy(0,i*28,28,28);
        this->direction[i]=temp1;
    }
}
Tank::~Tank()
{

}
void Tank::emove()
{
   int act=rand()%10,shoo=rand()%10;
   if(act<3)
   {
       this->idex=rand()%4;
   }
   else
   {
       if(this->idex==UP)
       {
           if(this->posy-1>=0)
           {
               if(block(this->posx,this->posy-1))
               {
                   this->posy-=1;
               }
               else
               {
                   this->idex=rand()%4;
               }
           }


           if(mmap[this->posx][this->posy]==GRASS)
           {
               this->ingrass=1;
           }
           else if(mmap[this->posx][this->posy]==EMPTY)
           {
               this->ingrass=0;
           }
       }
       else if(this->idex==RIGHT)
       {
           if(this->posx+1<26)
           {
               if(block(this->posx+1,this->posy))
               {
                this->posx+=1;
               }
               else
               {
                  this->idex=rand()%4;

               }
           }
           if(mmap[this->posx][this->posy]==GRASS)
           {
               this->ingrass=1;
           }
           else if(mmap[this->posx][this->posy]==EMPTY)
           {
               this->ingrass=0;
           }
       }
       else if(this->idex==DOWN)
       {
           if(this->posy+1<26)
           {
               if(block(this->posx,this->posy+1))
               {
                   this->posy+=1;
               }
               else
               {
                  this->idex=rand()%4;
               }
           }
           if(mmap[this->posx][this->posy]==GRASS)
           {
               this->ingrass=1;
           }
           else if(mmap[this->posx][this->posy]==EMPTY)
           {
               this->ingrass=0;
           }
       }
       else if(this->idex==LEFT)
       {
           if(this->posx-1>=0)
           {
               if(block(this->posx-1,this->posy))
               {
                   this->posx-=1;
               }
               else
               {
                   this->idex=rand()%4;
               }
           }
           if(mmap[this->posx][this->posy]==GRASS)
           {
               this->ingrass=1;
           }
           else if(mmap[this->posx][this->posy]==EMPTY)
           {
               this->ingrass=0;
           }
       }

   }
   if(shoo<3)
   {
       this->shoot();
   }
}
void Tank::shoot()
{
        if(this->idex==UP)
        {
            if(this->posy!=0)
            {
                bullet temp{this->posx,this->posy-1,this->idex,this->type};
                allbullet.push_back(temp);
            }
        }
        else if(this->idex==RIGHT)
        {
            if(this->posx!=25)
            {
                bullet temp{this->posx+1,this->posy,this->idex,this->type};
                allbullet.push_back(temp);
            }
        }
        else if(this->idex==DOWN)
        {
            if(this->posy!=25)
            {
            bullet temp{this->posx,this->posy+1,this->idex,this->type};
            allbullet.push_back(temp);
            }
        }
        else if(this->idex==LEFT)
        {
            if(this->posx!=0)
            {
                bullet temp{this->posx-1,this->posy,this->idex,this->type};
                allbullet.push_back(temp);
            }
        }

}
