#include <iostream>
using namespace std;
int p[100005];
int find(int x)
{
    if (x != p[x])
        p[x] = find(p[x]);
    return p[x];
}
void unio(int x, int y)
{
    p[find(x)] = find(y);
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
        p[i] = i;
    while (m--)
    {
        char c;
        int a, b;
        cin >> c >> a >> b;
        if (c == 'M')
            unio(a, b);
        if (c == 'Q')
            find(a) == find(b) ? cout << "Yes\n" : cout << "No\n";
    }
}