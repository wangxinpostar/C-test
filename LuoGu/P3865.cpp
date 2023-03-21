#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m;
int a[N];
int f[N][20];
void prest()
{
    for (int i = 1; i <= log2(n); i++)
    {
        for (int j = 1; j + (1 << i) - 1 <= n; j++)
        {
            f[j][i] = max(f[j][i - 1], f[j + (1 << i - 1)][i - 1]);
        }
    }
}
int qst(int l, int r)
{
    int k = log2(r - l + 1);
    return max(f[l][k], f[r - (1 << k) + 1][k]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        f[i][0] = a[i];
    }
    prest();
    int l, r;
    while (m--)
    {
        cin >> l >> r;
        cout << qst(l, r) << "\n";
    }
}