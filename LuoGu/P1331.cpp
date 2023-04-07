#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
int R, C, p[1010][1010], d[] = {-1, 0, 1, 0, -1}, dd[] = {0, 0, 1, 1, 0}, ans;
char m[1010][1010];
bool check(int x, int y)
{
    int res = 0;
    for (int i = 0; i < 4; i++)
    {
        if (m[x + dd[i]][y + dd[i + 1]] == '#')
        {
            res++;
        }
    }
    if (res == 3)
    {
        return false;
    }
    else
    {
        return true;
    }
}
void bfs(int x, int y)
{
    queue<pii> q;
    q.push({x, y});
    p[x][y] = true;
    while (q.size())
    {
        pii ver = q.front();
        q.pop();
        int x = ver.first, y = ver.second;
        for (int i = 0; i < 4; i++)
        {
            int xx = x + d[i];
            int yy = y + d[i + 1];
            if (xx >= 1 && xx <= R && yy >= 1 && yy <= C && !p[xx][yy] && m[xx][yy] == '#')
            {
                p[xx][yy] = true;
                q.push({xx, yy});
            }
        }
    }
}
int main()
{
    cin >> R >> C;
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            cin >> m[i][j];
        }
    }
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            if (!check(i, j))
            {
                cout << "Bad placement.";
                return 0;
            }
            if (m[i][j] == '#' && !p[i][j])
            {
                ans++;
                bfs(i, j);
            }
        }
    }
    cout << "There are " << ans << " ships.";
    return 0;
}