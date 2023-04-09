#include<bits/stdc++.h>
using namespace std;
int dp[1005],w[1005],v[1005];
int main()
{
    int t,m;
    cin>>m>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>w[i]>>v[i];
    }
    for(int i=1;i<=t;i++)
    {
        for(int j=m;j>=w[i];j--)
        {
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    cout<<dp[m];
}