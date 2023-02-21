#include<bits/stdc++.h>
#include<string>
using namespace std;
#define int long long
int a[50010],c[50010];
int t;
int getsum(int n)
{
    int r=0;
    while(n>0)
    {
        r+=c[n];
        n-=n&(-n);
    }
    return r;
}
void updata(int n,int x)
{
    while(n<=t)
    {
        c[n]+=x;
        n+=n&(-n);
    }
}
signed main()
{
    int n;
    cin>>n;
    for(int T=1;T<=n;T++)
    {
        memset(a,0,sizeof(a));
        memset(c,0,sizeof(c));
        cin>>t;
        for(int i=1;i<=t;i++)
        {
            cin>>a[i];
            updata(i,a[i]);
        }
        string s;
        int a,b;
        cout<<"Case "<<T<<":\n";
        while(cin>>s&&s[0]!='E')
        {
            cin>>a>>b;
            if(s[0]=='Q')
            {
                cout<<getsum(b)-getsum(a-1);
            }
            if(s[0]=='A')
            {
                updata(a,b);
            }
            if(s[0]=='S')
            {
                updata(a,-b);
            }
        }
    }
}