#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int cnt = 0;
    double a, b = s.size();
    if (s[0] == '-')
        b -= 1;
    for (int i = 0; i < int(s.size()); i++)
    {
        if (s[i] - '0' == 2)
            cnt++;
    }
    a = double(cnt) / b;
    if (s[0] == '-')
    {
        a *= 1.5;
    }
    if (s[s.size() - 1] % 2 == 0)
    {
        a *= 2;
    }
    a = round(a * 10000) / 10000;
    a *= 100;
    printf("%.2f%%\n", a);
}