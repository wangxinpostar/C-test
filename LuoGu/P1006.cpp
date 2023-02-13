#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cmath>
int dp[150][150][150];
int mp[150][150];
using namespace std;
int main()
{   
    int m,n;
    cin>>m>>n;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>mp[i][j];
        }
    }
    for(int k=1;k<=m+n-1;k++)
    for(int i=1;i<=m,i<=k;i++)
    {
        for(int j=1;j<=m,j<=k;j++)
        {
            dp[k][i][j]=max(max(dp[k-1][i-1][j],dp[k-1][i][j-1]),max(dp[k-1][i-1][j-1],dp[k-1][i][j]))+mp[i][k-i+1]+mp[j][k-j+1];
            if(i==j)dp[k][i][j]-=mp[i][k-i+1];
        }
    }
    cout<<dp[m+n-1][m][m];
}