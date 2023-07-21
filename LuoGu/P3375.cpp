#include <iostream>
#include <string>
using namespace std;
const int N = 1e6 + 10;
int ne[N];
string p, s;
int main()
{
    cin >> s >> p;
    int m = p.size(), n = s.size();
    s = "s" + s;
    p = "p" + p;
    for (int i = 2, j = 0; i <= m; i++)
    {
        while (j && p[i] != p[j + 1])
            j = ne[j];
        if (p[i] == p[j + 1])
            j++;
        ne[i] = j;
    }
    for (int i = 1, j = 0; i <= n; i++)
    {
        while (j && s[i] != p[j + 1])
            j = ne[j];
        if (s[i] == p[j + 1])
            j++;
        if (j == m)
        {
            cout << i - j + 1 << '\n';
            j = ne[j];
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cout << ne[i] << ' ';
    }
}