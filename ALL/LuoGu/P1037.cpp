#include <bits/stdc++.h>
using namespace std;
int m[15][15];
int p[200];
int num[200];
int main()
{
    string n;
    int l;
    cin >> n >> l;
    int f, a;
    while (l--)
    {
        cin >> f >> a;
        m[f][a] = 1;
    }
    for (int i = 0; i <= 9; i++)
    {
        m[i][i] = 1;
    }
    for (int k = 0; k <= 9; k++)
    {
        for (int i = 0; i <= 9; i++)
        {
            for (int j = 0; j <= 9; j++)
            {
                m[i][j] = m[i][j] || (m[i][k] && m[k][j]);
            }
        }
    }

    for (int i = 0; i <= 9; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (m[i][j])
            {
                p[i]++;
            }
        }
    }
    num[1] = 1;
    for (int i = 0; i < n.size(); i++)
    {
        for (int j = 1; j < 200; j++)
        {
            num[j] *= p[n[i] - '0'];
        }
        for (int k = 1; k < 200; k++)
        {
            if (num[k] >= 10)
            {
                num[k + 1] += num[k] / 10;
                num[k] %= 10;
            }
        }
    }
    int o = 199;
    while (!num[o])
        o--;
    for (o; o >= 1; o--)
    {
        cout << num[o];
    }
}