#include<bits/stdc++.h>
using namespace std;
int main()
{
    double s,x,n=7,ans=0;
    cin>>s>>x;
    while(ans<s-x)
    {
        ans+=n;
        n*=0.98;
    }
    if(ans+n>s+x)
    {
        cout<<"n";
    }
    else
    {
        cout<<"y";
    }
}