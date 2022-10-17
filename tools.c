#include <stdio.h>
#include <stdlib.h>

int GetKey(){//获取键盘输入
    //todo
    int input;//键盘输入
    system("stty raw");//切换原始模式，不用回车输入
    input=getchar();
    system("stty cooked");
    return input;
}