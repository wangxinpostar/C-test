// 题目描述
// 设有 N \times NN×N 的方格图 (N \le 9)(N≤9)，我们将其中的某些方格中填入正整数，而其他的方格中则放入数字 00。如下图所示（见样例）:

// A
//  0  0  0  0  0  0  0  0
//  0  0 13  0  0  6  0  0
//  0  0  0  0  7  0  0  0
//  0  0  0 14  0  0  0  0
//  0 21  0  0  0  4  0  0
//  0  0 15  0  0  0  0  0
//  0 14  0  0  0  0  0  0
//  0  0  0  0  0  0  0  0
//                          B
// 某人从图的左上角的 AA 点出发，可以向下行走，也可以向右走，直到到达右下角的 BB 点。在走过的路上，他可以取走方格中的数（取走后的方格中将变为数字 00）。
// 此人从 AA 点到 BB 点共走两次，试找出 22 条这样的路径，使得取得的数之和为最大。

// 输入格式
// 输入的第一行为一个整数 NN（表示 N \times NN×N 的方格图），接下来的每行有三个整数，前两个表示位置，第三个数为该位置上所放的数。一行单独的 00 表示输入结束。

// 输出格式
// 只需输出一个整数，表示 22 条路径上取得的最大的和。

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