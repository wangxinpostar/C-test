#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <deque>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <algorithm>
using namespace std;
int n, sum, ans[15], p[10000][15];
void dfs(int x)
{
    if (x > 10)
    {
        if (n == 0)
        {
            for (int i = 1; i <= 10; i++)
            {
                p[sum][i] = ans[i];
            }
            sum++;
        }
    }
    else
    {
        for (int i = 1; i <= 3; i++)
        {
            if (n - i >= 0)
            {
                ans[x] = i;
                n -= i;
                dfs(x + 1);
                n += i;
            }
        }
    }
}
int main()
{
    cin >> n;
    if (n > 30)
    {
        cout << 0;
        return 0;
    }
    dfs(1);
    cout << sum << "\n";
    for (int i = 0; i < sum; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            cout << p[i][j] << " ";
        }
        cout << "\n";
    }
}