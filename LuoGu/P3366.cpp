#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int t, N, M, cnt, sum, from, to, val, p[5005], ans[5005];
bool st[5005];

struct Edge
{
    int from, to, val, next;
} m[400005];

void add(int from, int to, int val)
{
    m[++t].next = p[from];
    m[t].from = from;
    m[t].to = to;
    m[t].val = val;
    p[from] = t;
}

typedef pair<int, int> PII;
priority_queue<PII, vector<PII>, greater<PII>> heap;

void dist()
{
    ans[1] = 0;
    heap.push({0, 1});
    while (heap.size())
    {
        int d = heap.top().first, ver = heap.top().second;
        heap.pop();
        if (st[ver])
            continue;
        st[ver] = true;

        cnt++;
        sum += d;

        for (int i = p[ver]; i; i = m[i].next)
        {
            int j = m[i].to;
            if (m[i].val < ans[j])
            {
                ans[j] = m[i].val;
                heap.push({ans[j], j});
            }
        }
    }
}

int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= M; i++)
    {
        scanf("%d%d%d", &from, &to, &val);
        add(from, to, val);
        add(to, from, val);
    }
    memset(ans, 0x3f, sizeof(ans));
    dist();
    if (cnt == N)
    {
        printf("%d", sum);
    }
    else
    {
        printf("orz");
    }
}