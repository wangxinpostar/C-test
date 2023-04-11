#include <cstring>
#include <queue>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;
typedef pair<int, int> PII;
struct mm
{
    int from, to, val, next;
} mp[500010];

int p[500010], ans[500010], st[500010], t, u, v, w, n, m, s;

void add(int from, int to, int val)
{
    mp[++t].next = p[from];
    mp[t].from = from;
    mp[t].to = to;
    mp[t].val = val;
    p[from] = t;
}

void dist(int s)
{
    memset(ans, 0x3f, sizeof(ans));
    ans[s] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, s});
    while (heap.size())
    {
        auto t = heap.top(); // 取出当前已经确定的最短距离的点
        heap.pop();

        int ver = t.second;
        if (st[ver])
            continue; // 如果已经被标记过，说明当前的点的边是比较长的重边，直接跳过。
        st[ver] = true;
        for (int i = p[ver]; i; i = mp[i].next)
        {
            int j = mp[i].to;
            if (ans[j] > ans[ver] + mp[i].val)
            {
                ans[j] = ans[ver] + mp[i].val;
                heap.push({ans[j], j});
            }
        }
    }
}

int main()
{
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        add(u, v, w);
    }
    dist(s);
    for (int i = 1; i <= n; i++)
    {
        if(ans[i]!=0x3f3f3f3f)
        cout<<ans[i]<<" ";
        else
        cout<<INT32_MAX<<" ";
    }

}
