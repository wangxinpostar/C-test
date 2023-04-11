#include<bits/stdc++.h>
using namespace std;
int p[100],m[100];
void dfs(int n,int x)
{
    if(x>n)
    {
        for(int i=1;i<=n;i++)
        {
            printf("%5d",m[i]);
        }
        cout<<"\n";
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!p[i])
        {
            p[i]=1;
            m[x]=i;
            x++;
            dfs(n,x);
            x--;
            p[i]=0;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    dfs(n,1);
}