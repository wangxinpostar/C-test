#include<bits/stdc++.h>
#define int long long
using namespace std;
int m[10005];
signed main()
{
    int n,x,y,a,b,c,d,e;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>m[i];
    }
    for(int i=1;i<=n;i++)
    {
        x=m[i]/2;
        y=m[i]/2+m[i]%2;
        a=0,b=0;
        c=x,d=y;
        while(c)
        {
            a+=c%10;
            c/=10;
        }
        while(d)
        {
            b+=d%10;
            d/=10;
        }
        if(a==b||a+1==b)
        {
            cout<<x<<" "<<y<<"\n";
        }else
        {
            e=abs(b-a)/2;
                if(min(x,y)==x)
                {
                    cout<<x-e<<" "<<y+e<<"\n";
                }
                else 
                cout<<x+e<<" "<<y-e<<"\n";
        }
    }
        // int n,m,x,s[1005];
    // cin>>n;
    // while(n--)
    // {
    //     int p=0,t=0;
    //     memset(s,0,sizeof(s));
    //     cin>>m;
    //     for(int i=1;i<=m;i++)
    //     {
    //         cin>>x;
    //         if(x==2)
    //         {
    //             t++;
    //         }
    //         s[i]=t;
    //     }
    //     for(int i=1;i<m;i++)
    //     {
    //         if(s[i]*2==s[m])
    //         {
    //             cout<<i<<"\n";
    //             p=1;
    //             break;
    //         }
    //     }
    //     if(!p)
    //     cout<<"-1\n";
    // }
}