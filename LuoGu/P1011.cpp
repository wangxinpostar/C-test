#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int dp[55],ddpp[55];
int main()
{
    dp[0]=dp[1]=dp[2]=1;
    for(int i=3;i<55;i++)
    {
        dp[i]+=dp[i-1]+dp[i-2];
    }
    dp[0]=dp[1]=dp[2]=0;
    for(int i=3;i<55;i++)
    {
        ddpp[i]=dp[i]-dp[i-1];
    }
    int a,n,nn,m,x;
    cin>>a>>nn>>m>>x;
    if(x<3)cout<<a;
    else
    for(int j=1;j<=100;j++)
    {
        n=nn-1;
        int ans=a+ddpp[n-1]*a+ddpp[n-2]*j;
        if(ans==m)
        {
            cout<<a+ddpp[x-1]*a+ddpp[x-2]*j;
        }
    }
}