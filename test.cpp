#include<bits/stdc++.h>
using namespace std;
struct XY
{
    double x,y;
};
bool f[100005]={1,1};

void E(int x)
{
    for(int i=2;i<=x;i++)
    {
        if(f[i])
        {
            continue;
        }
        for(int j=i*2;j<=x;j+=i)
        {
            f[j]=true;
        }
    }
}

int main()
{
    // int n,m;
    // cin>>n;
    // E(100005);
    // for (int i = 0; i < n; i++)
    // {
    //     cin>>m;
    //     if(!f[m])
    //     {
    //         cout<<m<<" ";
    //     }
    // } 


    // XY m[3];
    // for(int i=0;i<3;i++)
    // {
    //     cin>>m[i].x>>m[i].y;
    // }
    // double d = sqrt (pow(m[0].x-m[1].x,2)+pow(m[0].y-m[1].y,2))+
    // sqrt (pow(m[0].x-m[2].x,2)+pow(m[0].y-m[2].y,2))+
    // sqrt (pow(m[2].x-m[1].x,2)+pow(m[2].y-m[1].y,2));
    // printf("%.2f",d);

    // int n,m,t,p;
    // cin>>n;
    // for(int i=0;i<n;i++)
    // {
    //     cin>>t;
    //     if(t==1)
    //     {
    //         continue;
    //     }
    //     p=1;
    //     for(int j=2;j*j<=t;j++)
    //     {
    //         if(t%j==0)
    //         {
    //             p=0;
    //             break;
    //         }
    //     }
    //     if(p)
    //     {
    //         cout<<t<<" ";
    //     }
    // }
}