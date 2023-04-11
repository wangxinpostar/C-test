#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int m[400000];
int main()
{
    int n,q,w,p,x;
    long long ans=0;
    cin>>n>>q>>w;
    for(int i=1;i<=n;i++)
    {
        cin>>m[i];
    }
    while(q--)
    {
        cin>>p>>x;
        m[p]=x;
        sort(m,m+n);
        ans=0;
        for(int i=1;i<n;i++)
        {
            int l=i,r=n;
            while(l<r)
            {
                int mid=(l+r)>>1;
                if(l==mid||r+1==mid)
                {
                    if(m[i]+m[r]<=w)
                    {
                        l=r;
                    }
                    break;
                }
                if(m[i]+m[mid]<=w)
                {
                    l=mid;       
                }
                else
                {
                    r=mid-1;
                }

            }
            ans+=l-i+(2*m[i]<=w);
        }
        cout<<ans<<endl;
    }
}