#include <bits/stdc++.h>
using namespace std;
struct ma
{
    int x, y, val;
} p[500];

int main()
{
    int m, n, k;
    cin >> m >> n >> k;
    int x, t = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> x;
            if (x)
            {
                p[t++] = {i, j, x};
            }
        }
    }
    sort(p, p + t, [](ma p1, ma p2)
         { return p1.val > p2.val; });
    int ans = p[0].x * 2 + 1, hs = p[0].val;
    if (ans > k)
    {
        cout << 0;
        return 0;
    }
    else
    {
        ans -= p[0].x - 1;
        for (int i = 1; i < t; i++)
        {
            ans += p[i].x - 1 + abs(p[i].x - p[i - 1].x) + abs(p[i].y - p[i - 1].y) + 1;
            if (ans > k)
            {
                cout << hs;
                return 0;
            }
            else
            {
                ans -= p[i].x - 1;
                hs += p[i].val;
            }
        }
    }
    cout << hs;
}