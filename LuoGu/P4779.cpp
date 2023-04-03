#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;
typedef pair<int, int> PII;
int p[200015], ans[200015], t;
bool st[200015];
struct mp
{
    int from, to, val, next;
} m[200015];

void add(int from, int to, int val)
{
    m[++t].next = p[from];
    m[t].from = from;
    m[t].to = to;
    m[t].val = val;
    p[from] = t;
}

void dist(int s)
{
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    memset(ans, 0x3f, sizeof(ans));
    ans[s] = 0;
    heap.push({0, s});
    while (heap.size())
    {
        int ver = heap.top().second;
        heap.pop();
        if (st[ver])
            continue;
        st[ver] = true;
        for (int i = p[ver]; i; i = m[i].next)
        {
            int j = m[i].to;
            if (ans[j] > ans[ver] + m[i].val)
            {
                ans[j] = ans[ver] + m[i].val;
                heap.push({ans[j], j});
            }
        }
    }
}
int main()
{
    int n, m, s, u, v, w;
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        add(u, v, w);
    }
    dist(s);
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] != 0x3f3f3f3f)
            cout << ans[i] << " ";
        else
            cout << INT32_MAX << " ";
    }
}