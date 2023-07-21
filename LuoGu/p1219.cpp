#include <iostream>
#include <cstring>
using namespace std;
const int N = 30;
int n, cnt, r[N], c[N], p[N], v[N], st[N], path[N];
void dfs(int x)
{
    if (x >= n)
    {
        if (cnt < 3)
        {
            for (int i = 0; i < n; i++)
            {
                cout << path[i] << " ";
            }
            puts("");
        }
        cnt++;
    }
    for (int y = 1; y <= n; y++)
    {
        if (!c[y] && !p[x + y] && !v[y - x + n])
        {
            path[x] = y;
            c[y] = p[x + y] = v[y - x + n] = 1;
            dfs(x + 1);
            c[y] = p[x + y] = v[y - x + n] = 0;
        }
    }
}
int main()
{
    cin >> n;
    dfs(0);
    cout << cnt;
}