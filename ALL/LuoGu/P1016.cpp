#include<bits/stdc++.h>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
double cn[10][2];
double d1,c,d2,p;
int n;
double ans=1e5;
void dfs(int i,double x,double m)
{
    if(x<0||x>c)
    {
        return;
    }
    if(i==n+1)
    {
        ans=min(ans,m);
        return;
    }
    for(int j=i;j<=n+1&&(cn[j][0]-cn[i][0])/d2<=c;j++)
    {
        if(x*d2>=cn[j][0]-cn[i][0])
        {
            dfs(i+1,x-(cn[i+1][0]-cn[i][0])/d2,m);
        }
        else
        {
            dfs(i+1,(cn[j][0]-cn[i][0])/d2-(cn[i+1][0]-cn[i][0])/d2,m+((cn[j][0]-cn[i][0])/d2-x)*cn[i][1]);
        }
    }
    dfs(i+1,c-(cn[i+1][0]-cn[i][0])/d2,m+(c-x)*cn[i][1]);
}
int main()
{

    cin>>d1>>c>>d2>>p>>n;
    for(int i=1;i<=n;i++)
    {
        // 距离,油价
        cin>>cn[i][0]>>cn[i][1];
    }
    cn[n+1][0]=d1,cn[0][1]=p;
    dfs(0,0,0);
    if(ans==1e5)
    {
        cout<<"No Solution";
    }
    else
    {
        printf("%.2lf",ans);
    }
}