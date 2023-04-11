#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    int c = a, d = b;
    int n;
    cin >> n;
    int q, w, e, r;
    for (int i = 0; i < n; i++)
    {
        cin >> q >> w >> e >> r;
        if (w == r)
            continue;
        if (w == q + e)
        {
            a--;
            if (a == -1)
            {
                cout << "A\n"
                     << d - b << "\n";
                return 0;
            }
        }
        if (r == q + e)
        {
            b--;
            if (b == -1)
            {
                cout << "B\n"
                     << c - a << "\n";
                return 0;
            }
        }
    }
    return 0;
}