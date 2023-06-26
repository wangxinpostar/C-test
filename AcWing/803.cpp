#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
pii m[100005];
int n, res;
int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> m[i].first >> m[i].second;
    }

    sort(m, m + n);

    int st = 0, end = -0x3f3f3f3f;
    for (int i = 0; i < n; i++)
    {
        if (end >= m[i].first)
        {
            end = max(end, m[i].second);
        }
        else
        {
            res++;
            st = m[i].first;
            end = m[i].second;
        }
    }
    cout << res;
}