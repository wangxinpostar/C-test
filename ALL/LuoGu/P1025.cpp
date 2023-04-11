#include<bits/stdc++.h>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<iostream>
#include<queue>
#include<deque>
using namespace std;
int ans,n,k;
// void dfs(int x,int k,int n)
// {
//     if(k==1)
//     {
//         ans++;
//         return;
//     }
//     for(int i=x;i<=n/k;i++)
//     {
//         dfs(i,k-1,n-i);
        
//     }
//     return;
// }
// int main()
// {
//     cin>>n>>k;
//     dfs(1,k,n);
//     cout<<ans;
// }
int dp[300][300];
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        dp[i][1]=1;
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=k;j++)
        {
            if(j>i)
            dp[i][j]=0;
            else
            dp[i][j]=dp[i-1][j-1]+dp[i-j][j];
        }
    }
    cout<<dp[n][k];
}