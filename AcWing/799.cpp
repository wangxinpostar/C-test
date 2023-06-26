#include <iostream>
using namespace std;
int m[100005], p[100005], res = 0;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m[i];
    }
    for (int i = 0, j = 0; i < n; i++)
    {
        p[m[i]]++;
        while (p[m[i]] > 1)
        {
            p[m[j]]--;
            j++;
        }
        res = max(i - j + 1, res);
    }
    cout << res;
}