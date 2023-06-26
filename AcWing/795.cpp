#include <iostream>
using namespace std;
int n, q, l, r, a[100005], s[100005];
int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    while (q--)
    {
        cin >> l >> r;
        cout << s[r] - s[l - 1] << endl;
    }
}