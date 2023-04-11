#include<iostream>
#include<queue>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef pair<int,int>pii;
int t,sum,p[300000],N,M,from, to, val,cnt,ans[300000];
bool st[300000];
struct edge
{
	int from, to, val,next;
} m[500000];
void add(int from,int to,int val)
{
	m[++t].next=p[from];
	m[t].from=from;
	m[t].to=to;
	m[t].val=val;
	p[from]=t;
}
void dist()
{
	priority_queue<pii,vector<pii>,greater<pii>>heap;
	heap.push({0,1});
	ans[1]=0;
	while(heap.size())
	{
		int d=heap.top().first,ver=heap.top().second;
		heap.pop();
		if(st[ver])continue;
		st[ver]=true;
		cnt++;
		sum+=d;
		for(int i=p[ver]; i; i=m[i].next)
		{
			int j=m[i].to;
			if(ans[j]>m[i].val)
			{
				ans[j]=m[i].val;
				heap.push({ans[j],j});
			}
		}
	}
}
int main()
{
	cin>>N>>M;
	for(int i=0; i<M; i++)
	{
		cin>>from>>to>>val;
		add(from,to,val);
		add(to,from,val);
	}
	memset(ans,0x3f,sizeof(ans));
	dist();
	if(cnt==N)
	{
		cout<<sum;
	}
	else
	{
		cout<<"orz";
	}
}
