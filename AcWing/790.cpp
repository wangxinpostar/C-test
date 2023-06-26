#include <iostream>
using namespace std;
int main()
{
    double l = -1000, r = 1000, y;
    cin >> y;
    while (r - l > 1e-8)
    {
        double mid = (l + r) / 2;
        if (mid * mid * mid > y)
            r = mid;
        else
            l = mid;
    }
    printf("%lf", l);
}