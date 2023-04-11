#include <bits/stdc++.h>
int a[100005], b[100005];
const int mod = 1000000007;
using namespace std;
int main()
{
    long long n, nn;
    cin >> n;

    cin >> n;
    for (int i = n - 1; i >= 0; i--)
    {
        cin >> a[i];
    }

    cin >> nn;
    for (int i = nn - 1; i >= 0; i--)
    {
        cin >> b[i];
    }
    long long ans = 0, t, k = 1;
    for (int i = 0; i < max(n, nn); i++)
    {
        t = max(max(a[i], b[i]) + 1, 2);
        ans = (ans + (a[i] - b[i]) * k) % mod;
        k = (t * k) % mod;
    }
    cout << ans % mod;
}