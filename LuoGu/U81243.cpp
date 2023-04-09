#include<iostream>
#include<cstring>
#include<functional>
#include<cmath>
using namespace std;
const int N=1e6;
int a[N],s[N];
void updata(int l,int r,int x)
{
    s[l]+=x;
    s[r+1]-=x;
}
int main()
{
    int n,m,l,r,y;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        updata(i,i,a[i]);
    }
    for(int i=1;i<=m;i++)
    {
        cin>>l>>r>>y;
        updata(l,r,y);
    }
    for(int i=1;i<=n;i++)
    {
        a[i]=a[i-1]+s[i];
        cout<<a[i]<<" ";
    }
}