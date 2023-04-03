#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, p, t, a, h;
    double ans = 100000;
    cin >> n >> t >> a;
    for (int i = 0; i < n; i++)
    {
        cin >> h;
        if (abs(t - h * 0.006 - a) < ans)
        {
            ans = abs(t - h * 0.006 - a);
            p = i + 1;
        }
    }
    cout << p;
}
