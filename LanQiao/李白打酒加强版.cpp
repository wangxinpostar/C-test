#include <iostream>
using namespace std;
const int mod=1e9+7;
int ans,p[105][105][105];
int dfs(int n,int m,int h)
{
    if(n==0&&m==1&&h==1)
    {
      return 1;
    }
    if(n<0||m<1||h<1||h+n>m)
    {
      return 0;
    }
    if(p[n][m][h])return p[n][m][h];
   return  p[n][m][h]=(dfs(n,m-1,h-1)%mod+dfs(n-1,m,2*h)%mod)%mod;
}
int main()
{
  int n,m,h=2;
  cin>>n>>m;
  cout<<dfs(n,m,h);
  return 0;
}