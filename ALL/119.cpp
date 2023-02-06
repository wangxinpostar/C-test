// #include<bits/stdc++.h>
// using namespace std;
// const int mod=80112002;
// int N,M,A,B,R;
// int f[5000005],chu[5000005],ru[5000005],ans[5000005];
// struct AB
// {
//     int a,b,n;
// }m[5000005];

// int main()
// {
//     queue<int> q;
//     cin>>N>>M;
//     for (int i = 1; i <= M; i++)
//     {
//         cin>>A>>B;
//         m[i].a=A;
//         m[i].b=B;
//         m[i].n=f[A];
//         f[A]=i;
//         chu[A]++;
//         ru[B]++;
//     }
//     for (int i = 1; i <= N; i++)
//     {
//         if(ru[i]==0)
//         {
//             q.push(i);
//             ans[i]=1;
//         }
//     }
//     while (!q.empty())
//     {
//         int A=q.front();
//         q.pop();
//         for(int t=f[A];t;t=m[t].n)
//         {
//             B=m[t].b;
//             ans[B]+=ans[A];
//             ans[B]%=mod;
//             ru[B]--;
//             if(ru[B]==0)
//             {
//                 if(chu[B]==0)
//                 {
//                     R+=ans[B];
//                     R%=mod;
//                 }
//                 else
//                 {
//                     q.push(B);
//                 }
//             }
//         }
//     }
//     cout<<R<<endl;
// }

//动态规划


#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int ddpp[1005];
int w[1005],v[1005];
int main()
{
    // int t,m;
    // cin>>t>>m;
    // for(int i=1;i<=m;i++)
    // {
    //     cin>>w[i]>>v[i];
    // }
    // for (int i = 1; i <= m; i++)
    // {
    //     for(int j = 1;j <=t; j++)
    //     {
    //         if(j>=w[i])
    //         dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
    //         else
    //         dp[i][j]=dp[i-1][j];
    //     }
    // }
    // cout<<dp[m][t];

    // for(int i=1;i<=m;i++)
    // {
    //     for(int j=t;j>=0;j--)
    //     {
    //         if(j>=w[i])
    //         ddpp[j]=max(ddpp[j],ddpp[j-w[i]]+v[i]);
    //     }
    // }
    // cout<<ddpp[t];
}