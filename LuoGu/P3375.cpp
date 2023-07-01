#include <iostream>
using namespace std;
string p, s;
int ne[1000005];
int main()
{
    cin >> s >> p;

    int m = p.size();
    int n = s.size();

    p = 'p' + p;
    s = 's' + s;

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