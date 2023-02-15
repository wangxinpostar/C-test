#include <bits/stdc++.h>
using namespace std;
int m[300000], p[300000];
int main()
{
    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> m[i];
            p[i] = m[i] - m[i - 1];
        }
        for (int i = 1; i <= n; i++)
        {
            if (m[i] >= i)
            {
                p[1] += 1;
            }
            else
            {
                p[i - m[i] + 1] += 1;
            }
            p[i + 1] -= 1;
        }
        k = 0;
        for (int i = 1; i <= n; i++)
        {
            k += p[i];
            if(k>=1)
            cout<<"1 ";
            else
            cout<<"0 ";
        }
        cout << "\n";
    }
}