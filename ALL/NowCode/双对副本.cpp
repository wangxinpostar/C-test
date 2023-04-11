#include<bits/stdc++.h>
using namespace std;
int t[5],m[30];
int t1,t2,ans,temp;
void dfs(int x,int n)
{
    if(x>n)
    {
        ans=min(ans,max(t1,t2));
        return;
    }
    t1+=m[x];
    dfs(x+1,n);
    t1-=m[x];
    t2+=m[x];
    dfs(x+1,n);
    t2-=m[x];
}
int main()
{
    for(int i=1;i<=4;i++)
    {
        cin>>t[i];
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=t[i];j++)
        {
            cin>>m[j];
        }
        t1=t2=0;
        ans=1000000;
        dfs(1,t[i]);
        temp+=ans;
    }
    cout<<temp;
}