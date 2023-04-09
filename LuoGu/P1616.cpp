#include<bits/stdc++.h>
using namespace std;
long long dp[10000005],w[10000005],v[10000005];
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
        for(int j=w[i];j<=m;j++)
        {
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    cout<<dp[m];
}