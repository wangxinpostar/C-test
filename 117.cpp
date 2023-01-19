#include <bits/stdc++.h>
using namespace std;
int m[105][105];
int f[105][105];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int r, c, ans;
int dfs(int i, int j)
{
    if (f[i][j])
    {
        return f[i][j];
    }
    f[i][j] = 1;
    for (int t = 0; t < 4; t++)
    {
        int xx = i + dx[t];
        int yy = j + dy[t];
        if (xx > 0 &&
            xx <= r &&
            yy > 0 &&
            yy <= c &&
            m[xx][yy] < m[i][j] &&
            m[xx][yy] < m[i][j])
        {
            dfs(xx, yy);
            f[i][j] = max(f[i][j], f[xx][yy] + 1);
        }
    }
    return f[i][j];
}
int main()
{
    cin >> r >> c;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> m[i][j];
        }
    }
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            dfs(i,j);
            cout<<f[i][j]<<" ";
        }
        cout<<endl;
    }
    
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cout<<f[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
