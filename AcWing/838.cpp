#include <iostream>
#include <algorithm>
using namespace std;
int h[100010], cnt;
void down(int u)
{
    int t = u;
    if (2 * u <= cnt && h[2 * u] < h[t])
        t = 2 * u;
    if (2 * u + 1 <= cnt && h[2 * u + 1] < h[t])
        t = 2 * u + 1;
    if (t != u)
    {
        swap(h[t], h[u]);
        down(t);
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> h[i], cnt++;
    for (int i = n / 2; i; i--)
        down(i);
    for (int i = 1; i <= n; i++)
        cout << h[1] << ' ', h[1] = h[cnt--], down(1);
}