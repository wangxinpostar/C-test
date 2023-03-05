#include <bits/stdc++.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <queue>
#include <deque>
#include <iostream>
using namespace std;
int ans = 10000;
int p[100];
void dfs(int x, int p1, int p2, int t, int s)
{
    if (x % 3 == 0 && t != s)
    {
        ans = min(ans, t);
        return;
    }
    int m = p[1], n = p[2];
    for (int i = 0; i < m; i++)
    {
        p[1]--;
        t++;
        dfs(x - 1, p[1], p[2], t, s);
        p[1]++;
        t--;
    }
    for (int i = 0; i < p[2]; i++)
    {
        p[2]--;
        t++;
        dfs(x - 2, p[1], p[2], t, s);
        p[2]++;
        t--;
    }
    return;
}
int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        p[(s[i] - '0') % 3]++;
    }
    int t = p[1] + p[2] * 2;
    if (t % 3 == 0)
    {
        cout << 0;
        return 0;
    }
    dfs(t, p[1], p[2], 0, s.size());
    if (ans == 10000)
    {
        cout << -1;
    }
    else
    {
        cout << ans;
    }
}