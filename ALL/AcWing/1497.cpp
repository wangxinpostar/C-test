#include<bits/stdc++.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<deque>
#include<queue>
#include<set>
#include<map>
using namespace std;
int hou[100],zhong[100],id[100];
int n;
vector<int>ans[100];
void build(int fl,int fr,int sl,int sr,int n)
{
    if(fl>fr)return;
    int val=hou[fr];
    ans[n].push_back(val);
    int k=id[val];
    build(fl,k-sl-1+fl,sl,k-1,n+1);
    build(k-sl+fl,fr-1,k+1,sr,n+1);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>hou[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>zhong[i];
        id[zhong[i]]=i;
    }
    build(1,n,1,n,0);
    for(int i=0;i<n;i++)
    {
        for(auto j:ans[i])
        {
            cout<<j<<" ";
        }
    }
}