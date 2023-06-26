#include <iostream>
using namespace std;
int p[100005], temp[100005];
long long merge(int p[], int l, int r)
{
    if (l >= r)
        return 0;

    int mid = l + r >> 1;

    long long res = merge(p, l, mid) + merge(p, mid + 1, r);

    int i = l, j = mid + 1, k = 0;

    while (i <= mid && j <= r)
    {
        if (p[i] <= p[j])
            temp[k++] = p[i++];
        else
        {
            temp[k++] = p[j++];
            res += mid - i + 1;
        }
    }

    while (i <= mid)
        temp[k++] = p[i++];

    while (j <= r)
        temp[k++] = p[j++];

    for (int i = l, j = 0; i <= r; i++, j++)
        p[i] = temp[j];
    return res;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i];
    cout << merge(p, 0, n - 1);
}