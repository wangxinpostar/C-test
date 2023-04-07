#include <iostream>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <queue>
using namespace std;
int mp[25][25], a[25], b[25], p[25], ans[25], n, m, maxx = 0x3f3f3f3f;
void dfs(int cnt, int x, int p[], int ans[])
{
    if (cnt > m || x > m)
        return;

    int pos = 1;

    dfs(cnt, x + 1, p, ans);

    for (int i = 0; i < n; i++)
    {
        if (p[i] < a[i])
        {
            pos = 0;
            break;
        }
    }

    if (!pos)
    {
        for (int j = 0; j < n; j++)
        {
            p[j] += mp[x][j];
        }

        ans[cnt] = x;

        dfs(cnt + 1, x + 1, p, ans);

        for (int j = 0; j < n; j++)
        {
            p[j] -= mp[x][j];
        }
    }

    if (pos && cnt <= maxx)
    {
        maxx = min(maxx, cnt);
        for (int i = 0; i < cnt; i++)
        {
            b[i] = ans[i] + 1;
        }
    }
}
int main()
{

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mp[i][j];
        }
    }
    dfs(0, 0, p, ans);
    cout << maxx << " ";
    for (int i = 0; i < maxx; i++)
    {
        cout << b[i] << " ";
    }
    return 0;
}
