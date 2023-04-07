#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
using namespace std;
int m[150][150],N,M,ans;
bool p[150][150];
int d[]={-1,0,1,0,-1};
void bfs(int x,int y)
{
    queue<pair<int,int>>q;
    q.push({x,y});
    p[x][y]=true;
    while(q.size())
    {
        pair<int,int> ver=q.front();
        q.pop();
        int x=ver.first;
        int y=ver.second;
        for(int i=0;i<4;i++)
        {
            int x2=x+d[i];
            int y2=y+d[i+1];
            if(x2>=1&&x2<=N&&y2>=1&&y2<=M&&m[x2][y2]!=0&&!p[x2][y2])
            {
                p[x2][y2]=true;
                q.push({x2,y2});
            }
        }
    }
}
int main()
{
    cin>>N>>M;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            scanf("%1d",&m[i][j]);
        }
    }
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            if(!p[i][j]&&m[i][j]!=0)
            {
                ans++;
                bfs(i,j);
            }
        }
    }
    printf("%d",ans);
    return 0;
}