#include <iostream>
using namespace std;
int q[100005], temp[100005];
void mergesort(int q[], int l, int r)
{
    if (l >= r)
        return;

    int mid = l + r >> 1;

    mergesort(q, l, mid), mergesort(q, mid + 1, r);

    int i = l, j = mid + 1, k = 0;

    while (i <= mid && j <= r)
        if (q[i] < q[j])
            temp[k++] = q[i++];
        else
            temp[k++] = q[j++];

    while (i <= mid)
        temp[k++] = q[i++];

    while (j <= r)
        temp[k++] = q[j++];

    for (int i = l, j = 0; i <= r; i++, j++)
        q[i] = temp[j];
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);
    mergesort(q, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", q[i]);
    return 0;
}
