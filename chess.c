#include <stdio.h>
#include "chess.h"

int chessCount(int board[][COL],int x,int y,enum Dir d){//数从(x,y)到d方向连子数
    //todo
    int count=0;
    int x2 = x;
    int y2 = y;
    while(1){
        switch(d){
            case LEFT:
                x2--;
                break;
            case RIGHT:
                x2++;
                break;
            case UP:
                y2--;
                break;
            case DOWN:
                y2++;
                break;
            case LEFT_UP:
                x2--;
                y2--;
                break;
            case LEFT_DOWN:
                x2--;
                y2++;
                break;
            case RIGHT_UP:
                x2++;
                y2--;
                break;
            case RIGHT_DOWN:
                x2++;
                y2++;
                break;
            default:
                printf("Error: 未知方位!");
                break;
        }

        //判断(x2,y2)是否与(x,y)相同
        if(x2<1||x2>COL||y2<1||y2>ROW||board[y2-1][x2-1]!=board[y-1][x-1]){
            break;
        }
        count++;
    }
    return count;
}

int isLegal(int board[][COL],int x,int y){//判断输入是否合法（内置规则集）
    //todo
    if(board[y-1][x-1]!=0){
        return 0;
    }
    return 1;
}