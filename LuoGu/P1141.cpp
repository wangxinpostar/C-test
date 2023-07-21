// 题目描述
// 有一个仅由数字 00 与 11 组成的 n \times nn×n 格迷宫。若你位于一格 00 上，那么你可以移动到相邻 44 格中的某一格 11 上，同样若你位于一格 11 上，那么你可以移动到相邻 44 格中的某一格 00 上。

// 你的任务是：对于给定的迷宫，询问从某一格开始能移动到多少个格子（包含自身）。

// 输入格式
// 有一个仅由数字 00 与 11 组成的 n \times nn×n 格迷宫。若你位于一格 00 上，那么你可以移动到相邻 44 格中的某一格 11 上，同样若你位于一格 11 上，那么你可以移动到相邻 44 格中的某一格 00 上。

// 你的任务是：对于给定的迷宫，询问从某一格开始能移动到多少个格子（包含自身）。

// 输出格式
// mm 行，对于每个询问输出相应答案。
#include <bits/stdc++.h>
using namespace std;
int f[1000 * 1000 + 10];
int find(int x)
{
    return f[x] == x ? x : f[x] = find(f[x]);
}
int p[1000 * 1000 + 10];
char s[1000 + 10][1000 + 10];
int d[] = {0, 1, 0, -1, 0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n * n; i++)
    {
        f[i] = i;
        p[i] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                int dx = i + d[k], dy = j + d[k + 1];
                if (dx >= 0 && dx < n && dy >= 0 && dy < n && s[dx][dy] != s[i][j])
                {
                    int l = find(i * n + j), r = find(dx * n + dy);
                    if (l != r)
                    {
                        f[r] = l;
                        p[l] += p[r];
                    }
                }
            }
        }
    }
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        cout << p[find(x * n + y)] << "\n";
    }
}