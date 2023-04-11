#include<bits/stdc++.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<deque>
#include<queue>
#include<set>
#include<map>
using namespace std;
int f[20010];
int father(int x)
{
    return x==f[x]?x:f[x]=father(f[x]);
}
void unionf(int x,int y)
{
    f[father(y)]=father(x);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        f[i]=i;
    }
    int m,x,y;
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        unionf(x,y);
    }
    int q;
    cin>>q;
    int c,d;
    for(int i=1;i<=q;i++)
    {
        cin>>c>>d;
        puts(father(c)==father(d)?"Yes":"No");
    }
}