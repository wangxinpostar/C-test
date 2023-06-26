#include <iostream>
using namespace std;
int lowbit(int x)
{
    return x & -x;
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int x, res = 0;
        cin >> x;
        while (x)
            res++, x -= lowbit(x);
        cout << res << " ";
    }
}