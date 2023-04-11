#include <bits/stdc++.h>
using namespace std;
int m[35][35], p[35][35], d[] = {-1, 0, 1, 0, -1};
int n;
void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    m[x][y] = 3;
    p[x][y] = true;
    while (q.size())
    {
        pair<int, int> ver = q.front();
        q.pop();
        int x = ver.first, y = ver.second;
        for (int i = 0; i < 4; i++)
        {
            int x2 = x + d[i];
            int y2 = y + d[i + 1];
            if (x2 >= 0 && x2 <= n + 1 && y2 >= 0 && y2 <= n + 1 && m[x2][y2] == 0 && !p[x2][y2])
            {
                p[x2][y2] = true;
                m[x2][y2] = 3;
                q.push({x2, y2});
            }
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> m[i][j];
        }
    }
    bfs(0, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (m[i][j] == 3)
                cout << 0 << " ";
            if (m[i][j] == 0)
                cout << 2 << " ";
            if (m[i][j] == 1)
                cout << 1 << " ";
        }
        cout << "\n";
    }
    return 0;
}