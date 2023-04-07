#include<iostream>
#include<cstring>
#include<cmath>
#include<queue>
#include<functional>
using namespace std;
int r,c,d[]={-1,0,1,0,-1},ans;
int m[510][510];
bool p[510][510];
void bfs(int x,int y)
{
    queue<pair<int,int>>q;
    q.push({x,y});
    p[x][y]=true;
    m[x][y]=1;
    while(q.size())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int xx=x+d[i];
            int yy=y+d[i+1];
            if(xx>=0&&xx<=r+1&&yy>=0&&yy<=c+1&&m[xx][yy]==0&&!p[xx][yy])
            {
                m[xx][yy]=1;
                p[xx][yy]=true;
                q.push({xx,yy});
            }
        }
    }
}
int main()
{
    cin>>r>>c;
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            char ch;
            cin>>ch;
            m[i][j]=ch-'0';
        }
    }
    bfs(0,0);
    for(int i=0;i<=r+1;i++)
    {
        for(int j=0;j<=c+1;j++)
        {
            if(m[i][j]==0)
            {
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}