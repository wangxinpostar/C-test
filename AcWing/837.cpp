#include <iostream>
using namespace std;
int p[100005], cnt[100005];
int find(int x)
{
    if (x != p[x])
        p[x] = find(p[x]);
    return p[x];
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
        cnt[i] = 1;
    }
    while (m--)
    {
        char c[2];
        int x, y;
        cin >> c;
        if (c[0] == 'C')
        {
            cin >> x >> y;

            if (find(x) != find(y))
                cnt[find(x)] += cnt[find(y)];

            p[find(y)] = find(x);
        }
        if (c[1] == '1')
        {
            cin >> x >> y;
            find(x) == find(y) ? cout << "Yes\n" : cout << "No\n";
        }
        if (c[1] == '2')
        {
            cin >> x;
            cout << cnt[find(x)] << '\n';
        }
    }
}