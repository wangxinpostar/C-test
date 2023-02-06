#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int m[15][15];
int dp[15][15][15][15];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,a,b,c;
	cin>>n;
	while(cin>>a>>b>>c)
	{
		if(a==b&&b==c&&c==0)
		{
			break;
		}
		m[a][b]=c;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				for(int l=1;l<=n;l++)
				{
					dp[i][j][k][l]=max(max(dp[i-1][j][k-1][l],dp[i-1][j][k][l-1]),
					max(dp[i][j-1][k-1][l],dp[i][j-1][k][l-1]))+m[i][j]+m[k][l];
					if(i==k&&j==l)
					{
						dp[i][j][k][l]-=m[i][j];
					}
				}
			}
		}
	}
	cout<<dp[n][n][n][n];
} 