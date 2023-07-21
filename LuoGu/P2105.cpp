#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int n, m;
int k;
int x[510], y[510];
int c[20010]; // 用来标记该位置是否被攻击的数组
int ans = 0;  // 棋盘上不会被攻击到的格子数
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++)
        cin >> x[i] >> y[i];
    // 从每行开始遍历
    for (int i = 1; i <= n; i++)
    {
        int num = m; // 初始时每行格子数为m
        for (int j = 1; j <= k; j++)
        { // 遍历每个K皇后
            if (x[j] == i)
            { // 若该行有K皇后，直接跳出；
                num = 0;
                break;
            }
            else
            { // 如果该行没有皇后，判断其他K皇后的列和两条对角线是否影响该行某个位置；
                if (c[y[j]] != i)
                { // 判断列；初始时c[y[j]] != i；一旦该列有K皇后，就标记该位置
                    c[y[j]] = i;
                    num--;
                }
                if (x[j] + y[j] - i >= 1 && x[j] + y[j] - i <= m && c[x[j] + y[j] - i] != i)
                { // 判断左下—右上对角线
                    num--;
                    c[x[j] + y[j] - i] = i;
                }
                if (y[j] + (i - x[j]) >= 1 && y[j] + (i - x[j]) <= m && c[y[j] + (i - x[j])] != i)
                { // 判断左上-右下对角线
                    num--;
                    c[y[j] + (i - x[j])] = i;
                }
            }
        }
        ans += num; // 每行扫描结束后加上该行不会被攻击到的格子数
    }
    cout << ans;
    return 0;
}