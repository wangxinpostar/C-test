#include <bits/stdc++.h>
using namespace std;
string s;
int n;
bool is(int x)
{
    unordered_set <string> hs; 
    for(int i=0;i<s.size();i++)
    {
        string t=s.substr(i,x);
        if(hs.count(t))return false;
        hs.emplace(t);
    }
    return true;
}
int main()
{
    cin>>n;
    cin>>s;
    int l=1,r=n;
    while(l<r)
    {
        int mid=l+r>>1;
        if(is(mid))
        {
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<r;
}