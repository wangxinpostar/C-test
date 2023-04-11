#include <iostream>
using namespace std;
int m[1010];
int main()
{
    int n, t = 0, k = 0;
    char a;
    cin >> n >> a;
    m[t] = 1;
    t++, n -= 1;
    for (int i = 3; n - 2 * i >= 0; i += 2)
    {
        m[t++] = i;
        n -= 2 * i;
    }
    for (int i = t - 1; i >= 0; i--)
    {
        for (int j = 0; j < k; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < m[i]; j++)
        {
            cout << a;
        }
        cout << "\n";
        k++;
    }
    k -= 2;
    for (int i = 1; i < t; i++)
    {
        for (int j = k; j > 0; j--)
        {
            cout << " ";
        }
        for (int j = 0; j < m[i]; j++)
        {
            cout << a;
        }
        cout << "\n";
        k--;
    }
    cout << n << "\n";
    return 0;
}