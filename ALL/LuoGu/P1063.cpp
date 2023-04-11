#include <bits/stdc++.h>
using namespace std;
int m[100];
int n, k, ans;
bool s(int x)
{
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}
void dfs(int x, int sum, int i)
{
    if (x == k)
    {
        if (s(sum))
        {
            ans++;
        }
        return;
    }
    if (x > k || i >= n)
        return;
    dfs(x + 1, sum + m[i], i + 1);
    dfs(x, sum, i + 1);
}
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> m[i];
    }
    dfs(0, 0, 0);
    cout << ans;
}