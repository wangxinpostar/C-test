#include<bits/stdc++.h>
using namespace std;
int c[105],h[105];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        memset(c,0,sizeof(c));
        c[0]=1;
        //高精度乘
        for(int j=1;j<=i;j++)
        {
            for(int l=0;l<100;l++)
            {
                if(c[l]==0)continue;
                c[l]=c[l]*j;
            }
            for(int l=0;l<100;l++)
            {
                if(c[l]>=10)
                {
                    c[l+1]+=c[l]/10;
                    c[l]%=10;
                }
            }
        }

        //高精度加
        for(int l=0;l<100;l++)
        {
            h[l]+=c[l];
            if(h[l]>=10)
            {
                h[l+1]+=1;
                h[l]-=10;
            }
        }
    }
    int r=101;
    while(h[r]==0&&r>=0)r--;
    for(int i=r;i>=0;i--)
    {
        cout<<h[i];
    }
    //结束
}