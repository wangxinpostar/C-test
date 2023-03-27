#include <bits/stdc++.h>
using namespace std;
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
int m[35][35];
int n;
void dfs(int x, int y)
{
    if (x > 0 && x < n && y > 0 && y < n && m[x][y] == 0)
    {
        m[x][y] = 2;
        dfs(x + 1, y);
        dfs(x, y + 1);
        dfs(x - 1, y);
        dfs(x, y - 1);
    }
}
int main()
{

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> m[i][j];
        }
    }
    for (int i = 1; i + 1 < n; i++)
    {
        int l = 0, r = n - 1;
        while (!m[i][l])
        {
            l++;
        }
        while (!m[i][r])
        {
            r--;
        }
        if (r >= l)
        {
            for (int k = l; k <= r; k++)
            {
                if (m[i][k] == 0)
                {
                    dfs(i, k);
                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j < n; j++)
                        {
                            cout << m[i][j] << " ";
                        }
                        cout << "\n";
                    }
                    return 0;
                }
            }
        }
    }
}