// // #include <bits/stdc++.h>
// // using namespace std;
// // typedef pair<int, int> PII;
// // int a[200010];
// // map<int, int> b;
// // int main()
// // {
// //     cout.tie(0), cin.tie(0), ios::sync_with_stdio(false);
// //     int n, x, y, t = 0, T = 0;
// //     cin >> n;
// //     long long ans = 0;
// //     for (int i = 0; i < n; i++)
// //     {
// //         cin >> y >> x;
// //         if (y == 1)
// //         {
// //             a[t++] = x;
// //         }

// //         else
// //         {
// //             int k = 0;
// //             for (auto q : b)
// //             {
// //                 if (q.first % y == 0)
// //                 {
// //                     ans += q.second;
// //                     break;
// //                 }
// //             }
// //             for (int j = 0; j < t; j++)
// //             {
// //                 if (a[j] % y == 0)
// //                 {
// //                     k++;
// //                 }
// //             }
// //             PII h = {i, k};
// //             b.insert(h);
// //             ans += k;
// //         }
// //     }
// //     cout << ans;
// // }
// // int a, b, s0, s1, ans;
// // char m[50][50];
// // int p[50][50];
// // int dfs(int x, int y)
// // {
// //     if (x >= 0 && x < a && y >= 0 && y < b && !p[x][y])
// //     {
// //         if (m[x][y] == '.')
// //         {
// //             p[x][y] = 1;
// //             ans++;
// //             dfs(x - 1, y), dfs(x + 1, y), dfs(x, y + 1), dfs(x, y - 1);
// //         }
// //     }
// //     return 0;
// // }
// // int main()
// // {
// //     cin >> a >> b;
// //     for (int i = 0; i < a; i++)
// //     {
// //         for (int j = 0; j < b; j++)
// //         {
// //             cin >> m[i][j];
// //             if (m[i][j] == '@')
// //             {
// //                 s0 = i, s1 = j;
// //             }
// //         }
// //     }
// //     dfs(s0 - 1, s1), dfs(s0 + 1, s1), dfs(s0, s1 + 1), dfs(s0, s1 - 1);
// //     cout << ans+1;
// //     return 0;
// // }
// #include <bits/stdc++.h>
// using namespace std;
// const long long mod = 1e9 + 7;
// long long qmi(int x, long long n, long long mod)
// {
//     long long ans = 1;
//     while (n)
//     {
//         if (n && 1)
//         {
//             ans = (ans * x) % mod;
//         }
//         x = (x * x) % mod;
//         n >>= 1;
//     }
//     return ans%mod;
// }
// int main()
// {
//     long long n;
//     cin >> n;
//     cout << qmi(2, n, mod);
// }
// // typedef pair<int, int> PII;
// // int a[200010];
// // unordered_map<int, int> c;
// // int main()
// // {
// //     cout.tie(0), cin.tie(0), ios::sync_with_stdio(false);
// //     int n, x, y, t = 0, T = 0;
// //     cin >> n;
// //     long long ans = 0;
// //     for (int i = 0; i < n; i++)
// //     {
// //         cin >> y >> x;
// //         if (y == 1)
// //         {
// //             c[x]++;
// //         }
// //         else
// //         {
// //             for (auto j : c)
// //             {
// //                 if (j.first % y == 0)
// //                 {
// //                     ans += j.second;
// //                 }
// //             }
// //         }
// //     }
// //     cout << ans;
// // }
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
int a[200010];
int main()
{
    cout.tie(0), cin.tie(0), ios::sync_with_stdio(false);
    int n, x, y, t = 0, T = 0,mmm=0;
    cin >> n;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> y >> x;
        mmm=max(mmm,x);
        if (y == 1)
        {
            a[x]++;
        }
        else
        {
            for (int k=1;k*x<=mmm;k++)
            {
                ans+=a[k*x];
            }
        }
    }
    cout << ans;
}