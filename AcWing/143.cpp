#include <iostream>
#include <cmath>
using namespace std;
const int N = 1e5 + 5;
int son[N * 31][2], cnt[N * 31], a[N], idx;
void insert(int x)
{
    int p = 0;
    for (int i = 30; i >= 0; i--)
    {
        int u = x >> i & 1;
        if (!son[p][u])
            son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p] = x;
}
int query(int x)
{
    int p = 0;
    for (int i = 30; i >= 0; i--)
    {
        int u = x >> i & 1;
        if (!son[p][!u])
            p = son[p][u];
        else
            p = son[p][!u];
    }
    return cnt[p];
}
int main()
{
    int n, x, res = -0x3f3f3f3f;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        insert(a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        res = max(res, a[i] ^ query(a[i]));
    }
    cout << res;
}