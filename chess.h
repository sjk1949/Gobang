#ifndef _CHESS_H
#define _CHESS_H

#define ROW 20 //行
#define COL 20 //列

enum Dir{//棋子周围方向
    LEFT,
    RIGHT,
    UP,
    DOWN,
    LEFT_UP,
    LEFT_DOWN,
    RIGHT_UP,
    RIGHT_DOWN
};

int chessCount(int board[][COL],int x,int y,enum Dir d);
int isLegal(int board[][COL],int x,int y);

#endif