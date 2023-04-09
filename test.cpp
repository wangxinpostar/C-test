// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 10;
// int n, m;
// int a[N];
// int f[N][20];
// void perstl()
// {
//     for(int i=1;i<=log2(n);i++)
//     {
//         for(int j=1;j+(1<<i)-1<=n;j++)
//         {
//             f[j][i]=max(f[j][i-1],f[j+(1<<i-1)][i-1]);
//         }
//     }
// }
// int qstl(int l,int r)
// {
//     int k=log2(r-l+1);
//     return max(f[l][k],f[r-(1<<k)+1][k]);
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0), cout.tie(0);
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> a[i];
//         f[i][0] = a[i];
//     }
//     perstl();
//     while(m--)
//     {
//         int l,r;
//         cin>>l>>r;
//         cout<<qstl(l,r)<<"\n";
//     }
// }
//// // // int m[35][35];
// int n;
// void dfs(int x, int y)
// {
//     if (x > 0 && x < n && y > 0 && y < n && m[x][y] == 0)
//     {
//         m[x][y] = 2;
//         dfs(x + 1, y);
//         dfs(x, y + 1);
//         dfs(x - 1, y);
//         dfs(x, y - 1);
//     }
// }
// int main()
// {
//
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cin >> m[i][j];
//         }
//     }
//     for (int i = 1; i + 1 < n; i++)
//     {
//         int l = 0, r = n - 1;
//         while (!m[i][l])
//         {
//             l++;
//         }
//         while (!m[i][r])
//         {
//             r--;
//         }
//         if (r >= l)
//         {
//             for (int k = l; k <= r; k++)
//             {
//                 if (m[i][k] == 0)
//                 {
//                     dfs(i, k);
//                     for (int i = 0; i < n; i++)
//                     {
//                         for (int j = 0; j < n; j++)
//                         {
//                             cout << m[i][j] << " ";
//                         }
//                         cout << "\n";
//                     }
//                     return 0;
//                 }
//             }
//         }
//     }
// }
// #include <iostream>
// using namespace std;
// int ans;
// void dfs(int n,int m,int h)
// {
//     if(n==0&&m==1&&h==1)
//     {
//       ans++;
//       return;
//     }
//     if(n<0||m<1||h<0)
//     {
//       return;
//     }
//     dfs(n,m-1,h-1);
//     dfs(n-1,m,2*h);
// }
// int main()
// {
//   int n,m,h;
//   cin>>n>>m>>h;
//   dfs(n,m,h);
//   cout<<ans;
//   return 0;
// }
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
// #include<bits/stdc++.h>
// using namespace std;
// const int mod=1e9+7;
// long long qmi(long long x,long long n,long long mod)
//{
//  long long res=1;
//  while(n)
//  {
//    if(n&1)
//    {
//      res=res*x%mod;
//    }
//    x=x*x%mod;
//    n>>=1;
//  }
//  return res%mod;
//}
// long long solve(int a,int b,int mod)
//{
//    if(a<b)return 0;
//    long long x=1,y=1;
//    for(int i=a,j=1;j<=b;j++,i--)
//    {
//      x=x*i%mod;
//      y=y*j%mod;
//    }
//    return x*qmi(y,mod-2,mod)%mod;
//}
// int main()
//{
//  int n,a,b;
//  cin>>n>>a>>b;
//  cout<<(qmi(2,n,mod)-solve(n,a,mod)-solve(n,b,mod)-1+mod+mod)%mod;
//}
// #include<cmath>
// #include<iostream>
// #include<cstring>
// const long long mod=1e9+7;
// using namespace std;
// long long qmi(long long x,long long n,long long mod)
// {
// 	long long res=1;
// 	while(n)
// 	{
// 		if(n&1)
// 		{
// 			res=res*x%mod;
// 		}
// 		x=x*x%mod;
// 		n>>=1;
// 	}
// 	return res%mod;
// }
// long long solve(long long n,long long a,long long mod)
// {
// 	long long x=1,y=1;
// 	for(int i=a,j=1;j<=a;j++)
// 	{
// 		x=x*i%mod;
// 		y=y*j%mod;
// 	}
// 	return x*y*qmi(y,mod-2,mod);
// }
// int main()
// {
// 	int t,n;
// 	cin>>t;
// 	for(int i=0;i<t;i++)
// 	{
// 		cin>>n;
// 		cout<<(qmi(2,n,mod)-1-n+(const int)1e9*mod)%mod;
// 	}
// }
// #include <bits/stdc++.h>
// using namespace std;
// int m[35][35], p[35][35], d[] = {-1, 0, 1, 0, -1};
// int n;
// void bfs(int x, int y)
// {
//     queue<pair<int, int>> q;
//     q.push({x, y});
//     m[x][y] = 3;
//     p[x][y] = true;
//     while (q.size())
//     {
//         pair<int, int> ver = q.front();
//         q.pop();
//         int x = ver.first, y = ver.second;
//         for (int i = 0; i < 4; i++)
//         {
//             int x2 = x + d[i];
//             int y2 = y + d[i + 1];
//             if (x2 >= 0 && x2 <= n + 1 && y2 >= 0 && y2 <= n + 1 && m[x2][y2] == 0 && !p[x2][y2])
//             {
//                 p[x2][y2] = true;
//                 m[x2][y2] = 3;
//                 q.push({x2, y2});
//             }
//         }
//     }
// }
// int main()
// {

//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             cin >> m[i][j];
//         }
//     }

//     bfs(0, 0);
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             if (m[i][j] == 3)
//                 cout << 0 << " ";
//             if (m[i][j] == 0)
//                 cout << 2 << " ";
//             if (m[i][j] == 1)
//                 cout << 1 << " ";
//         }
//         cout << "\n";
//     }
//     return 0;
// }
// #include<iostream>
// using namespace std;
// const int N=1e8+10;
// int m[N],t;
// bool p[N];
// int main()
// {
//     int n,q,x;
//     cin>>n>>q;
//     for(int i=2;i<=n;i++)
//     {
//         if(!p[i])m[++t]=i;
//         for(int j=1;j<=t&&i*m[j]<=n;j++)
//         {
//             p[i*m[j]]=true;
//             if(i%m[j]==0)break;
//         }
//     }
//     while(q--)
//     {
//         cin>>x;
//         cout<<m[x]<<"\n";
//     }
//     return 0;
// }
// #include <bits/stdc++.h>
// using namespace std;
// typedef pair<int, int> pii;
// const int N = 6e5;
// struct edge
// {
//     int from, to, val, next;
// } mp[N];
// int ans[N], p[N], cnt, n, m, t, from, to, val, sum;
// bool st[N];
// void add(int from, int to, int val)
// {
//     mp[++t].next = p[from];
//     mp[t].from = from;
//     mp[t].to = to;
//     mp[t].val = val;
//     p[from] = t;
// }
// void dist()
// {
//     priority_queue<pii, vector<pii>, greater<>> heap;
//     heap.push({0, 1});
//     ans[1] = 0;
//     while (heap.size() && cnt < n)
//     {
//         int d = heap.top().first;
//         int ver = heap.top().second;
//         heap.pop();
//         if (st[ver])
//             continue;
//         st[ver] = true;
//         cnt++;
//         sum += d;
//         for (int i = p[ver]; i; i = mp[i].next)
//         {
//             int j = mp[i].to;
//             if (ans[j] > mp[i].val)
//             {
//                 ans[j] = mp[i].val;
//                 heap.push({ans[j], j});
//             }
//         }
//     }
// }
// int main()
// {
//     cin >> n >> m;
//     for (int i = 1; i <= m; i++)
//     {
//         cin >> from >> to >> val;
//         add(from, to, val);
//         add(to, from, val);
//     }
//     memset(ans,0x3f,sizeof(ans));
//     dist();
//     if (cnt == n)
//     {
//         cout << sum;
//     }
//     else
//     {
//         cout << "orz";
//     }
//     return 0;
// }
#include<iostream>
#include<cmath>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<deque>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<functional>
#include<algorithm>
using namespace std;
int dp[100005],m[100005];
int main()
{
    int n,ans=0,x;
    cin>>n;
    for(int i=0;i<n;i++)cin>>m[i];
    for(int i=0;i<n;i++)cin>>x;
    for(int i=0;i<n;i++)
    {
        dp[i]=1;
        for(int j=0;j<i;j++)
        {
            if(m[j]<m[i])
            {
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        ans=max(ans,dp[i]);
    }
    cout<<ans;
}