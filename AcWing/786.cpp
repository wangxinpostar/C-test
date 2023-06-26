#include <iostream>
using namespace std;
const int N = 1e5 + 5;
int m[N];
int quick(int l, int r, int k)
{
    if (l >= r)
        return m[l];

    int x = m[l + r >> 1];
    int i = l - 1, j = r + 1;

    while (i < j)
    {
        while (m[++i] < x)
            ;
        while (m[--j] > x)
            ;
        if (i < j)
            swap(m[i], m[j]);
    }

    if (j - l + 1 >= k)
        return quick(l, j, k);
    else
        return quick(j + 1, r, k - (j - l + 1));
}
int main()
{
    int n, k;

    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> m[i];

    cout << quick(0, n - 1, k);
}