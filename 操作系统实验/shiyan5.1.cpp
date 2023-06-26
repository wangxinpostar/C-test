#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
const int block_time = 10; // ����ʱ��Ƭ�ĳ���Ϊ10��
const int MAXPCB = 100;    // ������������
// ������̽ṹ��
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
// ��ʼ������
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
// �����ݺ���
int readData()
{
    FILE *fp;
    char fname[20];
    int i;
    cout << "������������ļ���:";
    cin >> fname;
    if ((fp = fopen(fname, "r")) == NULL)
    {
        cout << "����,�ļ��򲻿�,�����ļ���" << endl;
    }
    else
    {
        while (!feof(fp))
        {
            fscanf(fp, "%s %d %d %d", pcbs[quantity].name, &pcbs[quantity].status,
                   &pcbs[quantity].time, &pcbs[quantity].privilege);
            quantity++;
        } // ��������������
        cout << "��������������" << endl;
        cout << "������\t����״̬\t����ʱ��\t������\t" << endl;
        for (i = 0; i < quantity; i++)
        {
            cout << pcbs[i].name << "\t" << pcbs[i].status << "\t\t" << pcbs[i].time << "\t\t" << pcbs[i].privilege << "\t" << endl;
        }
        return (1);
    }
    return (0);
}
// ��������,�Թ���һ���㷨ʹ��
void init()
{
    int i;
    for (i = 0; i < MAXPCB; i++)
    {
        pcbs[i].finished = 0;
        pcbs[i].wait_time = 0;
    }
}
// �Ƚ��ȳ��㷨
void FIFO()
{
    int i, j;
    int total;
    // ���FIFO�㷨ִ����
    cout << endl
         << "*****************************************************" << endl;
    cout << "FIFO�㷨ִ����:" << endl;
    cout << "������\t�ȴ�ʱ��" << endl;
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
    cout << "�ܵȴ�ʱ��:" << total << "\tƽ���ȴ�ʱ��:" << total / quantity << endl;
}
// �����������㷨
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
    // �������������ִ����
    cout << endl
         << "***********************************************************" << endl;
    cout << "����������ִ����:" << endl;
    cout << "������\t�ȴ�ʱ��" << endl;
    for (i = 0; i < quantity; i++)
    {
        cout << pcbs[queue[i]].name << "\t" << pcbs[queue[i]].wait_time << endl;
    }
    total = 0;
    for (i = 0; i < quantity; i++)
    {
        total += pcbs[i].wait_time;
    }
    cout << "�ܵȴ�ʱ��:" << total << "\tƽ���ȴ�ʱ��:" << total / quantity << endl;
}
// ʱ��Ƭ��ת�����㷨
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
    cout << "ʱ��Ƭ��ת����ִ����:" << endl;
    for (i = 0; i < total; i++)
    {
        cout << pcbs[queue[i]].name << " ";
        avg_wait_time += pcbs[queue[i]].wait_time;
    }
    avg_wait_time /= quantity;

    cout << "����ִ�����ȴ�ʱ�䣺" << endl;
    for (i = 0; i < quantity; i++)
    {
        cout << pcbs[i].name << "��" << pcbs[i].wait_time << endl;
    }
    cout << "ƽ���ȴ�ʱ�䣺" << avg_wait_time << endl;
}

// ��ʾ
void version()
{
    cout << "/********************* ���̵��� ********************/";
    cout << endl
         << endl;
}
// ������
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
