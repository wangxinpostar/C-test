#include <iostream>
#include <functional>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int p[1010][1010], d[] = {-1, 0, 1, 0, -1}, n, ans;
char m[1010][1010];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> m[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (m[i][j] == '#')
            {
                ans++;
                for (int k = 0; k < 4; k++)
                {
                    if (m[i + d[k]][j + d[k + 1]] == '.')
                    {
                        ans--;
                        break;
                    }
                }
            }
        }
    }
    cout << ans;
}