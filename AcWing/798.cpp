#include <iostream>
using namespace std;
const int N = 1e3 + 5;
int a[N][N], s[N][N];
void insert(int x1, int y1, int x2, int y2, int x)
{
    s[x1][y1] += x;
    s[x1][y2 + 1] -= x;
    s[x2 + 1][y1] -= x;
    s[x2 + 1][y2 + 1] += x;
}
int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            insert(i, j, i, j, a[i][j]);
        }
    }
    while (q--)
    {
        int x1, y1, x2, y2, x;
        cin >> x1 >> y1 >> x2 >> y2 >> x;
        insert(x1, y1, x2, y2, x);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
            cout << s[i][j] << " ";
        }
        cout << '\n';
    }
}