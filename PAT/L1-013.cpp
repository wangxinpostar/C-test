#include <iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int k = 1;
        for (int j = 1; j <= i; j++)
        {
            k *= j;
        }
        sum += k;
    }
    cout << sum << "\n";
}
