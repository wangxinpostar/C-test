#include <iostream>
const int N = 1000005;
int q[N], a[N];
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int hh = 0, tt = -1;
    for (int i = 0; i < n; i++)
    {
        if (hh <= tt && i - k + 1 > q[hh])
            hh++;

        while (hh <= tt && a[q[tt]] >= a[i])
            tt--;

        q[++tt] = i;

        if (i + 1 >= k)
            printf("%d ", a[q[hh]]);
    }
    puts("");

    hh = 0, tt = -1;
    for (int i = 0; i < n; i++)
    {
        if (hh <= tt && i - k + 1 > q[hh])
            hh++;

        while (hh <= tt && a[q[tt]] <= a[i])
            tt--;

        q[++tt] = i;

        if (i + 1 >= k)
            printf("%d ", a[q[hh]]);
    }
}