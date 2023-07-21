#include <iostream>
#include <algorithm>
using namespace std;
int m[1000001], t;
int main()
{
    int n, ans = -1, pos = -1;
    cin >> n;
    for (int i = 1; i <= n / i; i++)
    {
        if (n % i == 0)
        {
            if (i * i != n)
            {
                m[t++] = i;
                m[t++] = n / i;
            }
            else
            {
                m[t++] = i;
            }
        }
    }
    sort(m, m + t);
    if (t == 2)
    {
        cout << 1 << "\n"
             << m[1] << "\n";
        return 0;
    }
    for (int i = 1; i < t; i++)
    {
        int p = i;
        int sum = m[i];
        int j = i + 1;
        int k = 0;
        while (m[j] - m[i] == 1 && n % (sum * m[j]) == 0)
        {
            sum *= m[j];
            k++;
            i++;
            j++;
        }
        if (k > ans)
        {
            pos = p;
            ans = k;
        }
        i = p;
    }
    cout << ans + 1 << "\n";
    for (int i = 0; i <= ans; i++)
    {
        if (i != ans)
            cout << m[pos + i] << "*";
        else
            cout << m[pos + i] << "\n";
    }
}