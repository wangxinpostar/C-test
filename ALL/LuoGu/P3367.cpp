#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
const int N = 3e5;
int f[N];
int findf(int x)
{
    return x == f[x] ? x : f[x] = findf(f[x]);
}
void unionf(int x, int y)
{
    int a = findf(x);
    int b = findf(y);
    if (a != b)
    {
        f[a] = b;
    }
}
int main()
{
    int n, m, x, a, b;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        f[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> x;
        cin >> a >> b;
        if (x == 1)
        {
            unionf(a, b);
        }
        else
        {
            if (findf(a) == findf(b))
            {
                cout << "Y\n";
            }
            else
            {
                cout << "N\n";
            }
        }
    }
    return 0;
}