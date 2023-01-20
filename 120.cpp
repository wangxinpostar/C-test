#include <bits/stdc++.h>
using namespace std;
// const int maxm = 10010, maxt = 10000010;
// long long dp[maxt], w[maxm], v[maxm],vv[maxm];
long long dp[25][25];
bool m[25][25];
int n,x;
struct XY
{
    int x,y;
};
int main()
{
    XY b,ma;

    cin>>b.x>>b.y>>ma.x>>ma.y;
    b.x+=1,b.y+=1,ma.x+=1,ma.y+=1;

    m[ma.x][ma.y]=
    m[ma.x+1][ma.y+2]=
    m[ma.x+1][ma.y-2]=
    m[ma.x+2][ma.y+1]=
    m[ma.x+2][ma.y-1]=
    m[ma.x-1][ma.y+2]=
    m[ma.x-1][ma.y-2]=
    m[ma.x-2][ma.y+1]=
    m[ma.x-2][ma.y-1]=true;

    dp[1][0]=1;

    for(int i=1;i<=b.x;i++)
    {
        for(int j=1;j<=b.y;j++)
        {
            if(!m[i][j])
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }

    cout<<dp[b.x][b.y];

    // cin>>n>>x;
    // for(int i=0;i<n;i++)
    // {
    //     cin>>vv[i]>>v[i]>>w[i];
    // }
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=x;j>=0;j--)
    //     {
    //         if(j>=w[i])
    //         {
    //             dp[j]=max(dp[j]+vv[i],dp[j-w[i]]+v[i]);
    //         }
    //         else
    //         {
    //             dp[j]+=vv[i];
    //         }
    //     }
    // }
    // cout<<dp[x]*5;

    // int t, m;
    // cin >> t >> m;
    // for (int i = 0; i < m; i++)
    // {
    //     cin >> w[i] >> v[i];
    // }
    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = w[i]; j <= t; j++)
    //     {
    //         dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    //     }
    // }
    // cout << dp[t];


}