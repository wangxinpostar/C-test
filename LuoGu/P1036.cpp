#include <iostream>
using namespace std;
int cnt, res, n, k, m[30];
bool tp[30];
bool isprimes(int x)
{
    for (int i = 2; i <= x / i; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}
void dfs(int x, int ans, int j)
{
    if (x == k)
    {
        if (isprimes(ans))
        {
            res++;
        }
        return;
    }
    for (int i = j; i < n; i++)
    {

        dfs(x + 1, ans + m[i], i + 1);
    }
}
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> m[i];
    dfs(0, 0, 0);
    cout << res;
}