#include<bits/stdc++.h>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;
int n,x,y[100005];
int main()
{
    long long ans=0,k=0;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        y[i]=x+y[i-1];
    }
    if(y[n]%3!=0)cout<<"0";
    else
    {
        int s=y[n]/3;
        for(int i=1;i<=n-1;i++)
        {
            if(y[i]==2*s)
            ans+=k;
            if(y[i]==s)
            k++;
        }
        cout<<ans;
    }
}
