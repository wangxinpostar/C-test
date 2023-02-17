#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    int n;
    long long s;
    cin>>n;
    while (n--)
    {
        long long ans = 0;
        for (int i = 0; i < 4; i++)
        {
            cin >> s;
            ans |= s;
        }
        cout << ans*4 << "\n";
    }
}