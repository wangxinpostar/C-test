#include <bits/stdc++.h>
using namespace std;
char m[150][150];
int r[150], c[150];
int main()
{
    int h, w;
    cin >> h >> w;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            cin >> m[i][j];
            if (m[i][j] == '#')
            {
                r[i] = 1;
                c[j] = 1;
            }
        }
    }
    for (int i = 1; i <= h; i++)
    {
        int p = 0;
        for (int j = 1; j <= w; j++)
        {
            cin >> m[i][j];
            if (r[i] && c[j])
            {
                cout << m[i][j];
                p = 1;
            }
            else
            {
                continue;
            }
        }
        if (p)
            cout << "\n";
    }
}