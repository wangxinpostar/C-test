#include<bits/stdc++.h>
using namespace std;
int m[35][35];
int n;
void dfs(int x, int y)
{
    if (x > 0 && x < n && y > 0 && y < n && m[x][y] == 0)
    {
        m[x][y] = 2;
        dfs(x + 1, y);
        dfs(x, y + 1);
        dfs(x - 1, y);
        dfs(x, y - 1);
    }
}
int main()
{

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> m[i][j];
        }
    }
    for (int i = 1; i + 1 < n; i++)
    {
        int l = 0, r = n - 1;
        while (!m[i][l])
        {
            l++;
        }
        while (!m[i][r])
        {
            r--;
        }
        if (r >= l)
        {
            for (int k = l; k <= r; k++)
            {
                if (m[i][k] == 0)
                {
                    dfs(i, k);
                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j < n; j++)
                        {
                            cout << m[i][j] << " ";
                        }
                        cout << "\n";
                    }
                    return 0;
                }
            }
        }
    }
}