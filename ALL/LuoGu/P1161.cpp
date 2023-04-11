#include <iostream>
using namespace std;
int m[2000000];
int main()
{
    int n;
    cin >> n;
    double a;
    int t;
    while (n--)
    {
        cin >> a >> t;
        while (t)
            m[(int)(a * t--)] ^= 1;
    }
    for (int i=0;; i++)
    {
        if (m[i])
        {
            cout << i;
            break;
        }
    }
}