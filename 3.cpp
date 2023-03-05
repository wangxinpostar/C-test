#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
long long m[200050];
unordered_map<long long, int> p;
unordered_set<int> q;
int main()
{
    long long n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> m[i];
        p.insert(pair<long long, int>(m[i], i));
    }
    long long x = k % n;
    long long y = k / n;
    sort(m, m + n);
    if (x == 0)
    {
        for (int i = 0; i < n; i++)
            cout << y << "\n";
    }
    else
    {
        for (int i = 0; i < x; i++)
            q.insert(p[m[i]]);
        for (int i = 0; i < n; i++)
        {
            if (q.count(i))
            {
                cout << y + 1 << "\n";
            }
            else
                cout << y << "\n";
        }
    }
}