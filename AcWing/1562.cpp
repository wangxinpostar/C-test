#include <bits/stdc++.h>
using namespace std;
int n, l, m, x;
int s[1500][1500], ss[10000];
int p[1500] = {0};
int main()
{
    cin >> n >> l;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            cin >> x;
            s[x][ss[x]++] = i + 1;
        }
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        int ans = 0;
        if (ss[x])
        {
            queue<int> t;
            unordered_set<int> se;
            for (int y = 0; y < ss[x]; y++)
            {
                if (p[x] == 0)
                {
                    t.push(s[x][y]);
                    se.insert(s[x][y]);
                    ans++;
                }
            }
            p[x] = 1;
            int c = 1, T = ss[x];
            while (c < l)
            {
                int r = 0;
                for (int v = 0; v < T; v++)
                {
                    int k = t.front();
                    t.pop();
                    for (int j = 0; j < ss[k]; j++)
                    {
                        if (p[k] == 0)
                        {
                            t.push(s[k][j]);
                            se.insert(s[k][j]);
                            ans++;
                            r++;
                        }
                    }
                    p[k] = 1;
                }
                c++;
                T = r;
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