#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    long long n, m, ans = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        if ((i + n) % 7 != 0 && (i + n) % 7 != 6)
        {

            ans += 250;
        }
    }
    cout << ans;
}