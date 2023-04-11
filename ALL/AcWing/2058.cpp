#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <vector>
#include <deque>
#include <queue>
#include <string>
#include <iostream>
#define long long int
using namespace std;
int get(string s, int x)
{
    int res=0;
    for(auto i:s)
    res=res*x+i-'0';
    return res;
}
signed main()
{
    int n;
    unordered_set<int> A;
    string a, b;
    cin >> a >> b;
    for (auto&c:a)
    {
        c^=1;
        A.insert(get(a,2));
        c^=1;   
    }
    for (auto&c:b)
    {
        int t=c;
        for(int i=0;i<=2;i++)
        {
            if(t-'0'!=i)
            {
                c=i+'0';
                int ans=get(b,3);
                if(A.count(ans))
                {
                    cout<<ans;
                    return 0;
                }
            }
            c=t;
        }
    }
}