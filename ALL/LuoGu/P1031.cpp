#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<cmath>
#include<string>
#include<functional>
#include<set>
#include<map>
#include<deque>
#include<queue>
#include<iostream>
using namespace std;
int m[150];
int c[150];
int main()
{
    int n,k=0;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>m[i];
        k+=m[i];
        c[i]+=c[i-1]+m[i];
    }
    for(int i=1;i<=n-1;i++)
    {
        if(c[i]!=k/n*i)
        {
            ans++;
        }
    }
    cout<<ans;
}