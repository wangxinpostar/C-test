#include <iostream>
using namespace std;
int main()
{
    int l, r, ans = 0;
    cin >> l >> r;
    for (int i = l; i <= r; i++)
    {
        int k = i;
        while (k)
        {
            if (k % 10 == 2)
            {
                ans++;
            }
            k /= 10;
        }
    }
    cout << ans;
}