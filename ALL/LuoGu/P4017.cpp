#include <bits/stdc++.h>
using namespace std;
const int mod = 80112002;
int p[500010], chu[500010], ru[500010], ans[500010];
queue<int> q;
struct mp
{
    int from, to, next;
} ma[500010];

int main()
{
    int n, m, from, to;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> from >> to;
        ma[i].from = from;
        ma[i].to = to;
        ma[i].next = p[from];
        chu[from]++;
        ru[to]++;
        p[from] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        if (ru[i] == 0)
        {
            q.push(i);
            ans[i] = 1;
        }
    }
    int res = 0;
    while (q.size())
    {
        int i = q.front();
        q.pop();
        for (int j = p[i]; j; j = ma[j].next)
        {
            ans[ma[j].to] = (ans[ma[j].to] + ans[ma[j].from]) % mod;
            ru[ma[j].to]--;
            if (ru[ma[j].to] == 0)
            {
                if (chu[ma[j].to] == 0)
                {
                    res = (res + ans[ma[j].to]) % mod;
                }
                q.push(ma[j].to);
            }
        }
    }
    cout << res % mod;
}