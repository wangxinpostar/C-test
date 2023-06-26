#include <iostream>
using namespace std;
const int N = 1e5 + 5;
int a[N], s[N];
void insert(int l, int r, int x)
{
    s[l] += x;
    s[r + 1] -= x;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        insert(i, i, a[i]);
    }
    while (m--)
    {
        int l, r, x;
        cin >> l >> r >> x;
        insert(l, r, x);
    }
    for (int i = 1; i <= n; i++)
    {
        s[i] += s[i - 1];
        cout << s[i] << " ";
    }
}