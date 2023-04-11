// 题目描述
// 观察下面的数字金字塔。
// 写一个程序来查找从最高点到底部任意处结束的路径，使路径经过数字的和最大。每一步可以走到左下方的点也可以到达右下方的点。
//         7 
//       3   8 
//     8   1   0 
//   2   7   4   4 
// 4   5   2   6   5 
// 在上面的样例中,从 7 \to 3 \to 8 \to 7 \to 57→3→8→7→5 的路径产生了最大

// 输入格式
// 第一个行一个正整数 rr ,表示行的数目。

// 后面每行为这个数字金字塔特定行包含的整数。

// 输出格式
// 单独的一行,包含那个可能得到的最大的和。
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