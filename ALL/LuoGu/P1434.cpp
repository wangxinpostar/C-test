#include<iostream>
#include<cmath>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<deque>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<functional>
#include<algorithm>
using namespace std;
int m[150][150];
int p[150][150];
int ans,r,c;
int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};
int dfs(int x,int y) {
	if(p[x][y]) {
		return p[x][y];
	}
	p[x][y]=1;
	for(int i=0; i<4; i++) {
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(xx>=0&&xx<r&&yy>=0&&yy<c&&m[xx][yy]<m[x][y]) {
			p[x][y]=max(dfs(xx,yy)+1,p[x][y]);
		}
	}
	return p[x][y];
}
int main() {
	
	cin>>r>>c;
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			cin>>m[i][j];
		}
	}
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			ans=max(ans,dfs(i,j));
		}
	}
	cout<<ans;
}