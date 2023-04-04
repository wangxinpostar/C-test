#include <bits/stdc++.h>
using namespace std;
int n, c[200],ans[200];
struct node
{
    int val, index;
} a[200];
void add(int x, int val)
{
    while (x<=n)
    {
        c[x] += val;
        x += x & (-x);
    }
}
int getsum(int x)
{
    int res = 0;
    while (x)
    {
        res += c[x];
        x -= x & (-x);
    }
    return res;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].val, a[i].index=i;
    }
    sort(a + 1, a + 1 + n, [](node a, node b)
         { return a.val > b.val; });
    for (int i = 1; i <= n; i++)
    {
        add(a[i].index,1);
        ans[a[i].index]=getsum(a[i].index-1);
    }
    for(int i=1;i<=n;i++)
    {
        cout<<i-ans[i]-1<<" ";
    }
    return 0;
}