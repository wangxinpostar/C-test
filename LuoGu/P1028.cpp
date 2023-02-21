#include <bits/stdc++.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <queue>
#include <deque>
using namespace std;
int ans;
int f[1010];
int s(int n)
{
    int result = 1;
    if(f[n])return f[n];
    for (int i = n / 2; i >= 1; --i)
        result += s(i);
    return f[n]=result;
}
int main()
{
    int n;
    cin >> n;
    cout<<s(n);
}