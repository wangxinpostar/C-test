#include <vector>
#include <iostream>
#include <string>
#include <deque>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;
int p[10005];
void isA()
{
    for (int i = 2; i < 10000; i++)
    {
        if (!p[i])
        {
            for (int j = 2; j * i < 10000; j++)
            {
                p[j * i] = 1;
            }
        }
    }
}
int main()
{
    isA();
    int n;
    cin >> n;
    for (int j = 1; j <= n / 2 - 1; j++)
    {
        cout << j * 2 + 2 << "=";
        for (int i = 2; i <= 10000; i++)
        {
            if (!p[i] && !p[j * 2 + 2 - i])
            {
                cout << i << "+" << j * 2 + 2 - i << "\n";
                break;
            }
        }
    }
}