#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int dp[1005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,x,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j>=1;j--)
        {
            cin>>x;
            dp[j]=max(dp[j-1]+x,dp[j]+x);
        }
    }
    for(int i=1;i<n;i++)
    {
        ans=max(ans,dp[i]);
    }
    cout<<ans;
}