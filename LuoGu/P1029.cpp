#include <bits/stdc++.h>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    int n, m, ans = 0;
    cin >> n >> m;
    if (n == m)
    {
        cout << 1;
        return 0;
    }
    for (int i = n; i * i <= m * n; i++)
    {
        if ((m * n) % i == 0 && __gcd(m * n / i, i) == n)
        {
            ans++;
        }
    }
    cout << ans * 2;
}