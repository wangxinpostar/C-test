#include<iostream>
#include<cstdio>
using namespace std;
int m[25];
int p[25][25];
int c[25],d[25];
int n,maxx=0,cc=2,h;
int dfs(int x,int ans)
{
	for (int i = x+1; i <= n; i++)
	{
		if(p[x][i])
		{
			c[cc++]=i;
			dfs(i,ans+m[i]);
			cc--;
		}
	}
	if(ans>maxx)
	{
		for(int i=1;i<=cc;i++)
		{
			d[i]=c[i];
		}
		maxx=ans;
		h=cc;
	}
	return maxx;
}
int main()
{
	cin>>n;
	for (int i = 1; i <= n; i++)
	{
		cin>>m[i];
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = i+1; j <= n; j++)
		{
			cin>>p[i][j];
		}	
	}
	for (int i = 1; i <= n; i++)
	{
		c[1]=i;
		dfs(i,m[i]);
	}
	for(int i=1;i<h;i++)
	{
		cout<<d[i]<<" ";
	}
	cout<<endl;
	cout<<maxx;
}