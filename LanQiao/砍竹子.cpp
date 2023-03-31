#include <bits/stdc++.h>
using namespace std;
vector<unordered_set<long long>> a;
long long doit(long long x)
{
    return sqrtl(x / 2 + 1);
}
int main()
{
    long long n;
    long long k;
    long long ans = 0;
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> k;
        while (k > 1)
        {
            if (!a[i - 1].count(k))
            {
                ans++;
            }
            a[i].insert(k);
            k = doit(k);
        }
    }
    cout << ans;
}