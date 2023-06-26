#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main(){
    pid_t pid;  //进程号
    char *message;
    int n;
    printf("fork progra starting\n");
    pid=fork(); //创建子进程，子进程便有了自己的生命周期并独立运行。
    switch(pid){
    case -1: //创建子进程失败
        perror("fork failed");
        exit(1);
    case 0: //子进程从这里运行
        message="child";
        n=5;
        break;
    default: //父进程从这里运行
        message="parent";
        n=3;
        break;
    }
    for(;n>0;n --){
        puts(message); //观察输出的情况，感受父子进程的工作情况
        sleep(1); //间隔1秒输出
    }
    exit(0);
}
