#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <cmath>
using namespace std;
char ans[100];
int k;
int main()
{
    int m, n;
    cin >> m >> n;
    cout << m << "=";
    while (m)
    {
        int i = m % n;
        m /= n;
        if (i < 0)
            i -= n, m++;
        if (i < 10)
            ans[k++] = i + '0';
        else
            ans[k++] = i + 'A' - 10;
    }

    for (k--; k >= 0; k--)
    {
        cout << ans[k];
    }
    cout << "(base" << n << ")";
}