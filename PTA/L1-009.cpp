#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n, a, b, suma = 0, sumb = 1;
    char c;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> c >> b;
        suma = a * sumb + b * suma;
        sumb = b * sumb;
        int d = abs(__gcd(suma, sumb));
        suma /= d;
        sumb /= d;
    }
    if (suma / sumb)
    {
        if (suma % sumb == 0)
        {
            cout << suma / sumb;
        }
        else
        {
            cout << suma / sumb << " " << suma % sumb << "/" << sumb;
        }
    }
    else
    {
        if (suma == 0)
        {
            cout << 0;
        }
        else
        {
            cout << suma << "/" << sumb;
        }
    }
}