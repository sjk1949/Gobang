#ifndef _GAME_H
#define _GAME_H

#include "chess.h"

#define CONTINUE 0 //继续条件
#define NEXT 1 //换人条件
#define EMPTY 0 //空
#define PLAYER1 1 //棋手1
#define PLAYER2 2 //棋手2
#define DRAW 3 //平局
#define ESC -1 //退出状态
#define DEBUG -2 //调试模式

#define MAXLINE 100 //字符串最大长度

extern int mouse_x,mouse_y;//光标位置

void game();
int Move(int board[][COL]);
void BoardPlace(int board[][COL],int x,int y,int who);
void ShowBoard(int board[][COL]);
void ClearBoard(int board[][COL]);
int isOver(int board[][COL],int x,int y);
void debug(char s[]);

#endif