#include <bits/stdc++.h>
using namespace std;
int n, l, m, x;
vector<int> s[2000];
unordered_set<int> se;
int p[2000][2000] = {0};
int main()
{
    cin >> n >> l;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            cin >> x;
            s[x].push_back(i + 1);
        }
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        p[x][x] = 1;
        if (s[x].size())
        {
            queue<int> t, g;
            se = unordered_set<int>();
            for (int y : s[x])
            {
                if (p[x][y] == 0 && p[y][x] == 0)
                {
                    p[x][y] = p[y][x] = 1;
                    t.push(y);
                }
            }
            int c = 1;
            while (t.size() && c <= l)
            {
                int k = t.front();
                t.pop();
                se.insert(k);
                for (int j : s[k])
                {
                    if (p[k][j] == 0 && p[j][k] == 0)
                    {
                        p[k][j] = p[k][j] = 1;
                        g.push(j);
                    }
                }
                if (!t.size())
                {
                    c++;
                    t = g;
                    g = queue<int>();
                }
            }
            memset(p, 0, sizeof(p));
            cout << se.size() - se.count(x) << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
    }
}