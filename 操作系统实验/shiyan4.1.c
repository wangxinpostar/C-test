#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int fd[2];
    pid_t pid1, pid2;
    char buf1[20], buf2[20];

    // 创建管道
    if (pipe(fd) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // 创建子进程1
    pid1 = fork();

    if (pid1 == -1)
    {
        perror("fork1");
        exit(EXIT_FAILURE);
    }
    else if (pid1 == 0) // 子进程1
    {
        close(fd[0]); // 关闭读取端

        // 写入数据到管道
        sprintf(buf1, "Hello from process 1!");
        write(fd[1], buf1, sizeof(buf1));

        close(fd[1]); // 关闭写入端
        exit(EXIT_SUCCESS);
    }
    else // 父进程
    {
        // 创建子进程2
        pid2 = fork();

        if (pid2 == -1)
        {
            perror("fork2");
            exit(EXIT_FAILURE);
        }
        else if (pid2 == 0) // 子进程2
        {
            close(fd[0]); // 关闭读取端

            // 写入数据到管道
            sprintf(buf2, "Hello from process 2!");
            write(fd[1], buf2, sizeof(buf2));

            close(fd[1]); // 关闭写入端
            exit(EXIT_SUCCESS);
        }
        else // 父进程
        {
            int status;
            close(fd[1]); // 关闭写入端

            // 读取子进程1写入的数据
            read(fd[0], buf1, sizeof(buf1));
            printf("Parent read from pipe: %s\n", buf1);

            // 读取子进程2写入的数据
            read(fd[0], buf2, sizeof(buf2));
            printf("Parent read from pipe: %s\n", buf2);

            close(fd[0]); // 关闭读取端

            // 等待子进程1、2结束
            waitpid(pid1, &status, 0);
            waitpid(pid2, &status, 0);
        }
    }

    return 0;
}
