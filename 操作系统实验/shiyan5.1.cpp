#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
const int block_time = 10; // 定义时间片的长度为10秒
const int MAXPCB = 100;    // 定义最大进程数
// 定义进程结构体
typedef struct node
{
    char name[20];
    int status;
    int time;
    int privilege;
    int finished;
    int wait_time;
    int executed_time;
    int start_time;
    int end_time;
} pcb;
pcb pcbs[MAXPCB];
int quantity;
// 初始化函数
void initial()
{
    int i;
    for (i = 0; i < MAXPCB; i++)
    {
        strcpy(pcbs[i].name, "");
        pcbs[i].status = 0;
        pcbs[i].time = 0;
        pcbs[i].privilege = 0;
        pcbs[i].finished = 0;
        pcbs[i].wait_time = 0;
    }
    quantity = 0;
}
// 读数据函数
int readData()
{
    FILE *fp;
    char fname[20];
    int i;
    cout << "请输入进程流文件名:";
    cin >> fname;
    if ((fp = fopen(fname, "r")) == NULL)
    {
        cout << "错误,文件打不开,请检查文件名" << endl;
    }
    else
    {
        while (!feof(fp))
        {
            fscanf(fp, "%s %d %d %d", pcbs[quantity].name, &pcbs[quantity].status,
                   &pcbs[quantity].time, &pcbs[quantity].privilege);
            quantity++;
        } // 输出所读入的数据
        cout << "输出所读入的数据" << endl;
        cout << "进程名\t进程状态\t所需时间\t优先数\t" << endl;
        for (i = 0; i < quantity; i++)
        {
            cout << pcbs[i].name << "\t" << pcbs[i].status << "\t\t" << pcbs[i].time << "\t\t" << pcbs[i].privilege << "\t" << endl;
        }
        return (1);
    }
    return (0);
}
// 重置数据,以供另一个算法使用
void init()
{
    int i;
    for (i = 0; i < MAXPCB; i++)
    {
        pcbs[i].finished = 0;
        pcbs[i].wait_time = 0;
    }
}
// 先进先出算法
void FIFO()
{
    int i, j;
    int total;
    // 输出FIFO算法执行流
    cout << endl
         << "*****************************************************" << endl;
    cout << "FIFO算法执行流:" << endl;
    cout << "进程名\t等待时间" << endl;
    for (i = 0; i < quantity; i++)
    {
        cout << pcbs[i].name << "\t" << pcbs[i].wait_time << endl;
        for (j = i + 1; j < quantity; j++)
        {
            pcbs[j].wait_time += pcbs[i].time;
        }
    }
    total = 0;
    for (i = 0; i < quantity; i++)
    {
        total += pcbs[i].wait_time;
    }
    cout << "总等待时间:" << total << "\t平均等待时间:" << total / quantity << endl;
}
// 优先数调度算法
void privilege()
{
    int i, j, p;
    int passed_time = 0;
    int total;
    int queue[MAXPCB];
    int current_privilege = 1000;
    for (i = 0; i < quantity; i++)
    {
        current_privilege = 1000;
        for (j = 0; j < quantity; j++)
        {
            if ((pcbs[j].finished == 0) && (pcbs[j].privilege < current_privilege))
            {
                p = j;
                current_privilege = pcbs[j].privilege;
            }
        }
        queue[i] = p;
        pcbs[p].finished = 1;
        pcbs[p].wait_time += passed_time;
        passed_time += pcbs[p].time;
    }
    // 输出优先数调度执行流
    cout << endl
         << "***********************************************************" << endl;
    cout << "优先数调度执行流:" << endl;
    cout << "进程名\t等待时间" << endl;
    for (i = 0; i < quantity; i++)
    {
        cout << pcbs[queue[i]].name << "\t" << pcbs[queue[i]].wait_time << endl;
    }
    total = 0;
    for (i = 0; i < quantity; i++)
    {
        total += pcbs[i].wait_time;
    }
    cout << "总等待时间:" << total << "\t平均等待时间:" << total / quantity << endl;
}
// 时间片轮转调度算法
void timer()
{
    int i, j, number, flag = 1;
    int passed_time = 0;
    int max_time = 0;
    int round = 0;
    int queue[1000];
    int total = 0;
    int start_time, end_time, wait_time;
    float avg_wait_time = 0;

    while (flag == 1)
    {
        flag = 0;
        number = 0;
        for (i = 0; i < quantity; i++)
        {
            if (pcbs[i].finished == 0)
            {
                number++;
                j = i;
            }
        }
        if (number == 1)
        {
            queue[total] = j;
            total++;
            pcbs[j].finished = 1;
            start_time = passed_time;
            passed_time += pcbs[j].time;
            end_time = passed_time;
            pcbs[j].executed_time = pcbs[j].time;
            pcbs[j].wait_time = 0;
            pcbs[j].start_time = start_time;
            pcbs[j].end_time = end_time;
        }
        if (number > 1)
        {
            for (i = 0; i < quantity; i++)
            {
                if (pcbs[i].finished == 0)
                {
                    flag = 1;
                    queue[total] = i;
                    total++;
                    if (pcbs[i].executed_time + block_time <= pcbs[i].time)
                    {
                        pcbs[i].executed_time += block_time;
                        passed_time += block_time;
                        pcbs[i].wait_time = passed_time - pcbs[i].start_time - pcbs[i].executed_time;
                    }
                    else
                    {
                        passed_time += pcbs[i].time - pcbs[i].executed_time;
                        pcbs[i].executed_time = pcbs[i].time;
                        pcbs[i].finished = 1;
                        pcbs[i].wait_time = passed_time - pcbs[i].start_time - pcbs[i].executed_time;
                        pcbs[i].end_time = passed_time;
                    }
                }
            }
        }
        round++;
    }

    if (queue[total - 1] == queue[total - 2])
    {
        total--;
    }

    cout << endl
         << "*******************************************************" << endl;
    cout << "时间片轮转调度执行流:" << endl;
    for (i = 0; i < total; i++)
    {
        cout << pcbs[queue[i]].name << " ";
        avg_wait_time += pcbs[queue[i]].wait_time;
    }
    avg_wait_time /= quantity;

    cout << "进程执行流等待时间：" << endl;
    for (i = 0; i < quantity; i++)
    {
        cout << pcbs[i].name << "：" << pcbs[i].wait_time << endl;
    }
    cout << "平均等待时间：" << avg_wait_time << endl;
}

// 显示
void version()
{
    cout << "/********************* 进程调度 ********************/";
    cout << endl
         << endl;
}
// 主函数
int main()
{
    int flag;
    version();
    initial();
    flag = readData();
    if (flag == 1)
    {
        FIFO();
        init();
        privilege();
        init();
        timer();
    }
}
