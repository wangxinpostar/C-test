#include <bits/stdc++.h>
int p[2505], t[1000][1000];
using namespace std;
int main()
{
    int n;
    cin >> n;
    int m;
    while (n--)
    {
        cin >> m;
        for (int i = 1; i <= m * m; i++)
        {
            p[i] = i;
        }
        int f = 1, l = m * m, k;
        for (int i = 1; i <= m; i++)
        {
            if (i % 2 != 0)
            {
                k = 1;
                while (k <= m)
                {
                    if (k % 2 == 0)
                    {
                        t[i][k++] = p[f++];
                    }
                    else
                    {
                        t[i][k++] = p[l--];
                    }
                }
            }
            else
            {
                k = m;
                while (k >= 1)
                {
                    if (k % 2 == 0)
                    {
                        t[i][k--] = p[l--];
                    }
                    else
                    {
                        t[i][k--] = p[f++];
                    }
                }
            }
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cout << t[i][j] << " ";
            }
            cout << endl;
        }
    }

    // int n,m,p[55];
    // cin>>n,m;
    // while(n--)
    // {
    //     cin>>m;
    //     for(int i=0;i<m;i++)
    //     {
    //         cin>>p[i];
    //     }
    //     sort(p,p+m,greater<int>());
    //     if(p[0]==p[m-1])
    //     {
    //         cout<<"NO"<<endl;
    //         continue;
    //     }
    //     cout<<"YES"<<endl;
    //     cout<<p[0]<<" ";
    //     for(int i=m-1;i>0;i--)
    //     {
    //         cout<<p[i]<<" ";
    //     }
    //     cout<<endl;
    // }

    // long long n,m,ans;
    // cin>>n;
    // while(n--)
    // {
    //     cin>>m;
    //     ans=m*(m-1)%mod;
    //     for(int i=1;i<=m;i++)
    //     {
    //         ans*=i;
    //         ans%=mod;
    //     }
    //     cout<<ans<<endl;
    // }

    // int n,a,b,c;
    // cin>>n;
    // while (n--)
    // {
    //     cin>>a>>b>>c;
    //     int maxx=max(max(a,b),c);
    //     if(a==b&&b==c)
    //     {
    //         cout<<1<<" "<<1<<" "<<1<<endl;
    //         continue;
    //     }
    //     if(a==b)
    //     {
    //         if(maxx==a)
    //         {
    //             cout<<1<<" "<<1<<" "<<a-c+1<<endl;
    //         }
    //         if(maxx==c)
    //         {
    //             cout<<c-a+1<<" "<<c-a+1<<" "<<0<<endl;
    //         }
    //     }
    //     if(a==c)
    //     {
    //         if(maxx==a)
    //         {
    //             cout<<1<<" "<<a-b+1<<" "<<1<<endl;
    //         }
    //         if(maxx==b)
    //         {
    //             cout<<b-a+1<<" "<<0<<" "<<b-a+1<<endl;
    //         }
    //     }
    //     if(b==c)
    //     {
    //         if(maxx==a)
    //         {
    //             cout<<0<<" "<<a-b+1<<" "<<a-b+1<<endl;
    //         }
    //         if(maxx==b)
    //         {
    //             cout<<b-a+1<<" "<<1<<" "<<1<<endl;
    //         }
    //     }
    //     if(a!=b&&a!=c&&b!=c)
    //     {
    //         if(maxx==a)
    //         {
    //             cout<<0<<" "<<a-b+1<<" "<<a-c+1<<endl;
    //         }
    //         if(maxx==b)
    //         {
    //             cout<<b-a+1<<" "<<0<<" "<<b-c+1<<endl;
    //         }
    //         if(maxx==c)
    //         {
    //             cout<<c-a+1<<" "<<c-b+1<<" "<<0<<endl;
    //         }
    //     }
    // }

    // int n;
    // long long a,b,c,d,ans;
    // cin>>n;
    // while (n--)
    // {
    //     ans=0;
    //     cin>>a>>b>>c>>d;
    //     if(a==0)
    //     {
    //         if(b||c||d)
    //         {
    //             cout<<1<<endl;
    //         }
    //         else
    //         {
    //             cout<<0<<endl;
    //         }
    //     }
    //     else
    //     {
    //         ans+=min(b,c)*2+a;
    //         ans+=min(a+1,abs(b-c)+d);
    //         cout<<ans<<endl;
    //     }
    // }
}