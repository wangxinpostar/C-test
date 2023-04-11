#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    int c[m];
    for (int i = 0; i < m; i++)
    {
        cin >> c[i];
    }
    for (int i = 0; i < n; i++)
    {
        next_permutation(c, c + m);
    }
    for (int i : c)
    {
        cout << i << " ";
    }
}