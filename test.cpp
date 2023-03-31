// // // #include <bits/stdc++.h>
// // // using namespace std;
// // // // const int N = 1e5 + 10;
// // // // int n, m;
// // // // int a[N];
// // // // int f[N][20];
// // // // void perstl()
// // // // {
// // // //     for(int i=1;i<=log2(n);i++)
// // // //     {
// // // //         for(int j=1;j+(1<<i)-1<=n;j++)
// // // //         {
// // // //             f[j][i]=max(f[j][i-1],f[j+(1<<i-1)][i-1]);
// // // //         }
// // // //     }
// // // // }
// // // // int qstl(int l,int r)
// // // // {
// // // //     int k=log2(r-l+1);
// // // //     return max(f[l][k],f[r-(1<<k)+1][k]);
// // // // }
// // // // int main()
// // // // {
// // // //     ios::sync_with_stdio(false);
// // // //     cin.tie(0), cout.tie(0);
// // // //     cin >> n >> m;
// // // //     for (int i = 1; i <= n; i++)
// // // //     {
// // // //         cin >> a[i];
// // // //         f[i][0] = a[i];
// // // //     }
// // // //     perstl();
// // // //     while(m--)
// // // //     {
// // // //         int l,r;
// // // //         cin>>l>>r;
// // // //         cout<<qstl(l,r)<<"\n";
// // // //     }
// // // // }
// // // int m[35][35];
// // // int n;
// // // void dfs(int x, int y)
// // // {
// // //     if (x > 0 && x < n && y > 0 && y < n && m[x][y] == 0)
// // //     {
// // //         m[x][y] = 2;
// // //         dfs(x + 1, y);
// // //         dfs(x, y + 1);
// // //         dfs(x - 1, y);
// // //         dfs(x, y - 1);
// // //     }
// // // }
// // // int main()
// // // {

// // //     cin >> n;
// // //     for (int i = 0; i < n; i++)
// // //     {
// // //         for (int j = 0; j < n; j++)
// // //         {
// // //             cin >> m[i][j];
// // //         }
// // //     }
// // //     for (int i = 1; i + 1 < n; i++)
// // //     {
// // //         int l = 0, r = n - 1;
// // //         while (!m[i][l])
// // //         {
// // //             l++;
// // //         }
// // //         while (!m[i][r])
// // //         {
// // //             r--;
// // //         }
// // //         if (r >= l)
// // //         {
// // //             for (int k = l; k <= r; k++)
// // //             {
// // //                 if (m[i][k] == 0)
// // //                 {
// // //                     dfs(i, k);
// // //                     for (int i = 0; i < n; i++)
// // //                     {
// // //                         for (int j = 0; j < n; j++)
// // //                         {
// // //                             cout << m[i][j] << " ";
// // //                         }
// // //                         cout << "\n";
// // //                     }
// // //                     return 0;
// // //                 }
// // //             }
// // //         }
// // //     }
// // // }
// // #include <iostream>
// // using namespace std;
// // int ans;
// // void dfs(int n,int m,int h)
// // {
// //     if(n==0&&m==1&&h==1)
// //     {
// //       ans++;
// //       return;
// //     }
// //     if(n<0||m<1||h<0)
// //     {
// //       return;
// //     }
// //     dfs(n,m-1,h-1);
// //     dfs(n-1,m,2*h);
// // }
// // int main()
// // {
// //   int n,m,h;
// //   cin>>n>>m>>h;
// //   dfs(n,m,h);
// //   cout<<ans;
// //   return 0;
// // }
// #include <iostream>
// using namespace std;
// int main()
// {
//   int m[10]={0};
//   int ans=0;
//   for(int i=1;;i++)
//   {
//     int x=i;
//     while(x)
//     {
//       int y=x%10;
//       x/=10;
//       m[y]++;
//       if(m[y]>2021)
//       {
//         cout<<ans;
//         return 0;
//       }
//     }
//     ans++;
//   }
//   cout<<ans;
//   return 0;
// }
// #include <iostream>
// #include <set>
// #include <unordered_set>
// using namespace std;
// long long m[100000];
// int main()
// {
//   long long n = 2021041820210418;
//   long long ans = 0, t = 0;
//   for (long long i = 1; i * i <= n; i++)
//   {
//     if (n % i == 0)
//     {
//       m[t++] = i;
//       m[t++] = n / i;
//     }
//   }
//   for (int i = 0; i < t; i++)
//   {
//     for (int j = 0; j < t; j++)
//     {
//       if (n % (m[i] * m[j]) == 0)
//       {
//         ans++;
//       }
//     }
//   }
//   cout << ans;
// }
// #include <iostream>
// using namespace std;
// int main()
// {
//   long long n;
//   cin>>n;
//   for(long long i=1;;i++)
//   {
//     if(2*i+i*(i-1)>=n*2)
//     {
//       cout<<i;
//       break;
//     }
//   }
//   return 0;
// }
#include<bits/stdc++.h>
using namespace std;
long long qmi(int x,int n,int mod)
{
  long long res=1;
  while(n)
  {
    if(n&1)
    {
      res=res*x%mod;
    }
    x=x*x%mod;
    n>>=1;
  }
  return res;
}
int main()
{
  cout<<qmi(2,10,1e9);
}