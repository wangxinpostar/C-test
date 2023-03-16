#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#define int long long
using namespace std;
int a[100005], b[100005];
signed main()
{
    int n, k, p, l = 1, r = 1;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> p;
        if (p < 0)
        {
            a[l++] = p;
        }
        else
        {
            b[r++] = p;
        }
    }
    l--, r--;
    sort(a + 1, a + 1 + l, greater<int>());
    int ans = INT64_MAX;
    if (l >= k)
    {
        ans = -a[l];
    }
    if (r >= k)
    {
        ans = min(ans, b[r]);
    }
    if (l >= k)
    {
        l = k;
        r = 0;
    }
    else
    {
        r = k - l;
    }
    while (l > 0)
    {
        int o = -a[l] + b[r] + min(-a[l], b[r]);
        l--, r++;
        ans = min(o, ans);
    }
    cout << ans;
}