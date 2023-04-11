#include <bits/stdc++.h>
using namespace std;
char c[10][10];
int d[] = {-1, 0, 1, 0, -1};
int ans, n, m, k;
unordered_set<string> a;
void dfs(int x, int y, int p, string s)
{
    if (p == k && !a.count(s))
    {
        a.insert(s);
        return;
    }
    if (p > k)
    {
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (x + d[i] <= n && x + d[i] >= 1 && y + d[i + 1] >= 1 && y + d[i + 1] <= m)
        {
            dfs(x + d[i], y + d[i + 1], p + 1, s + c[x + d[i]][y + d[i + 1]]);
        }
    }
    return;
}
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> c[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            string x="";
            x+=c[i][j];
            dfs(i, j, 0, x);
        }
    }
    cout << a.size();
}