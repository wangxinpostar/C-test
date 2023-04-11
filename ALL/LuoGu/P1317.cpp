#include <vector>
#include <iostream>
#include <string>
#include <deque>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;
int m[10005];
int main()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m[i];
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (m[i - 1] > m[i] && m[i + 1] >= m[i])
        {
            while (m[i + 1] == m[i])
            {
                i++;
                if (i == n - 1||m[i+1] < m[i])
                {
                    ans--;
                }
            }
            ans++;
        }
    }
    cout << ans;
}