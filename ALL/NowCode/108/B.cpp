#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int a[300000],b[300000];
int main()
{
    int n,t;
    cin>>n;
    while(n--)
    {
        long long ans=0;
        int p=1;
        cin>>t;
        for(int i=1;i<=t;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<=t;i++)
        {
            cin>>b[i];
        }
        for(int i=1;i<t;i++)
        {
            if((a[i]-b[i])%2)
            {
                cout<<-1<<"\n";
                p=0;
                break;
            }
            if(a[i]>b[i])
            {
                ans+=(a[i]-b[i])/2;
                a[i+1]+=a[i]-b[i];
            }
            else
            {
                ans+=(b[i]-a[i])/2;
                a[i+1]-=b[i]-a[i];
            }
        }
        if(p&&a[t]==b[t])
        cout<<ans<<"\n";
        else
        if(p)
        cout<<-1<<"\n";
    }
}