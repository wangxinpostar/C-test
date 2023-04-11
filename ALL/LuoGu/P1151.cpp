#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int k, p = 1;
    cin >> k;
    for (int i = 10000; i <= 30000; i++)
    {
        int b1 = i / 100;
        int b2 = (i - i / 10000 * 10000)/10;
        int b3 = i % 1000;
        if (b1 % k == 0 && b2 % k == 0 && b3 % k == 0)
        {
            cout << i << "\n";
            p = 0;
        }
    }
    if (p)
        cout << "No";
}