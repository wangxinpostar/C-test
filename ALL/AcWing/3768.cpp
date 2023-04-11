#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s;
    cin>>n>>s;
    int j=0;
    int ans=0,t=0;
    while(j<s.size())
    {
        if(s[j]=='x')
        {
            ans++;
            if(ans>=3)
            t++;
        }
        else
        {
            ans=0;
        }
        j++;
    }
    cout<<t;
}