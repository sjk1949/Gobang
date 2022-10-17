#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "chess.h"
#include "tools.h"

int player = PLAYER1;//先手玩家
void game(){//主程序
    //todo
    int status = CONTINUE;
    int result = 0;
    int playboard[ROW][COL];//初始化棋盘
    ClearBoard(playboard);

    while(1){
        //玩家走子
        do{
            ShowBoard(playboard);
        }while((status=Move(playboard)) == CONTINUE);//判断是否落子
        ShowBoard(playboard);
        if(status==ESC){
            break;
        }else if(status==DEBUG){//进入调试模式
            char consoleInput[MAXLINE]="";
            printf("已进入调试模式!\n");
            while(strcmp(consoleInput,"q")&&strcmp(consoleInput,"Q")){
                printf("Console: ");
                scanf("%s",&consoleInput);
            }
        }

        result = isOver(playboard,mouse_x,mouse_y);//判断是否结束
        if(result != CONTINUE){
            break;
        }else{//换手
            if(player == PLAYER1){
                player = PLAYER2;
            }else{
                player = PLAYER1;
            }
        }
    }

    //游戏结束
    switch(result){
        case PLAYER1:
            printf("PLAYER1 WIN!\n");
            break;
        case PLAYER2:
            printf("PLAYER2 WIN!\n");
            break;
        case DRAW:
            printf("平局!\n");
            break;
    }
}

void ShowBoard(int board[][COL]){//显示棋盘
    //todo
    printf("\x1b[H\x1b[2J");//清屏
    //显示
    int i = 0;
    printf("   ");
    for(i=1;i<=COL;i++){
        printf("%3d",i);
    }
    printf("\n");

    for(i=0;i<ROW;i++){
        printf("%3d",i+1);
        int j;
        for(j=0;j<COL;j++){
            if((i==mouse_y-1)&&(j==mouse_x-1)){//如果在光标位置
                if(board[i][j]==PLAYER1){
                    printf(" ■ ");
                }else if(board[i][j]==PLAYER2){
                    printf(" □ ");
                }else{
                    printf(" █ ");
                }
            }else{
                if(board[i][j]==PLAYER1){
                    printf(" ● ");
                }else if(board[i][j]==PLAYER2){
                    printf(" ○ ");
                }else{
                    printf(" . ");
                }        
            } 
        }
        printf("\n");
    }
}

void ClearBoard(int board[][COL]){//清空棋盘
    int i,j;
    for(i=0;i<ROW;i++){
        for(j=0;j<COL;j++){
            board[i][j]=0;
        }
    }
}

int mouse_x,mouse_y;//光标位置
int Move(int board[][COL]){//键盘控制光标(0-继续,1/2-落子)
    //todo
    int input=GetKey();//键盘输入
    
    if(input==3){//ctrl+C
        return ESC;
    }else if(input==96){//~,调试模式
        return DEBUG;
    }else if(input==13){//enter
        //落子
        if(isLegal(board,mouse_x,mouse_y)){
            BoardPlace(board,mouse_x,mouse_y,player);
            return NEXT;
        }else{
            printf("Error: 该位置无法落子!");
        }
    }else{//移动光标
        if(mouse_x<1||mouse_x>COL||mouse_y<1||mouse_y>ROW){
            mouse_x=1;
            mouse_y=1;
        }
        switch(input){
            case 65://up
                if(mouse_y>1){
                    mouse_y--;
                }
                break;
            case 66://down
                if(mouse_y<ROW){
                    mouse_y++;
                }
                break;
            case 68://left
                if(mouse_x>1){
                    mouse_x--;
                }
                break;
            case 67://right
                if(mouse_x<COL){
                    mouse_x++;
                }
                break;
            default:
                printf("Error: 未知指令%d %c",input,input);
                break;
        }
    }
    return CONTINUE;
}

void BoardPlace(int board[][COL],int x,int y,int who){//放置棋子
    //todo
    board[y-1][x-1]=who;
}

int isOver(int board[][COL],int x,int y){//判断是否结束
    //todo
    int count1 = chessCount(board,x,y,LEFT)+chessCount(board,x,y,RIGHT)+1;
    int count2 = chessCount(board,x,y,UP)+chessCount(board,x,y,DOWN)+1;
    int count3 = chessCount(board,x,y,LEFT_UP)+chessCount(board,x,y,RIGHT_DOWN)+1;
    int count4 = chessCount(board,x,y,RIGHT_UP)+chessCount(board,x,y,LEFT_DOWN)+1;

    if(count1>=5||count2>=5||count3>=5||count4>=5){//是否连成五子
        return board[y-1][x-1];
    }

    int i,j;
    for(i=0;i<ROW;i++){
        for(j=0;j<COL;j++){
            if(board[i][j]==EMPTY){
                return CONTINUE;
            }
        }
    }
    return DRAW;
}

void debug(char s[]){//debug函数
    //todo
}