#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <queue>
#include <iostream>
using namespace std;
int m[100];
int r[100][150];
int c[100][150];
int block[150][150];
void dfs(int x)
{
    if (x > 81)
    {
        for (int i = 1; i <= 81; i++)
        {
            cout << m[i] << " ";
            if (i % 9 == 0)
            {
                cout << "\n";
            }
        }
        exit(0);
    }
    if (m[x] != 0)
    {
        dfs(x + 1);
    }
    else
    {
        int row = (x - 1) / 9 + 1;
        int col = (x - 1) % 9 + 1;
        for (int i = 1; i <= 9; i++)
        {
            if (!r[row][i] && !c[col][i] && !block[(row - 1) / 3 * 3 + (col - 1) / 3 + 1][i])
            {
                m[x] = i;
                r[row][i] = 1, c[col][i] = 1, block[(row - 1) / 3 * 3 + (col - 1) / 3 + 1][i] = 1;
                dfs(x + 1);
                r[row][i] = 0,
                c[col][i] = 0, block[(row - 1) / 3 * 3 + (col - 1) / 3 + 1][i] = 0;
            }
        }
        m[x] = 0;
    }
    return;
}
int main()
{
    for (int i = 1; i <= 81; i++)
    {
        cin >> m[i];
        if (m[i] != 0)
        {
            int row = (i - 1) / 9 + 1;
            int col = (i - 1) % 9 + 1;
            r[row][m[i]] = 1;
            c[col][m[i]] = 1;
            block[(row - 1) / 3 * 3 + (col - 1) / 3 + 1][m[i]] = 1;
        }
    }
    dfs(1);
}