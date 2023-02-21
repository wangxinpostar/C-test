#include <bits/stdc++.h>
#include <cmath>
#include <algorithm>
int n;
double h, s1, v, l, k;
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    double H, S, V, L, K, N;
    cin >> h >> s1 >> v >> l >> k >> n;
    double t_max = sqrt(h / 5);
    double t_min = sqrt((h - k) / 5);
    int i_b = int(s1 - t_min * v + l), i_e = int(s1 - t_max * v);
    i_b = min(i_b, n);
    i_e = max(i_e, 0);
    cout << i_b - i_e;
}