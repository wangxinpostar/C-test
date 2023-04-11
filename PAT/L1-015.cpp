#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    double c;
    char a;
    cin >> c >> a;
    int r = int(c / 2 + 0.5);
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cout << a;
        }
        cout << "\n";
    }
}