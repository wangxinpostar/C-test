#include<iostream>
using namespace std;
const int N=1e3+5;
long long x,y,xx,yy,n,m,q;
long long a[N][N],s[N][N];
int main()
{
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
        }
    }
    while(q--)
    {
        cin>>x>>y>>xx>>yy;
        cout<<s[xx][yy]-s[xx][y-1]-s[x-1][yy]+s[x-1][y-1]<<"\n";
    }
    return 0;
}