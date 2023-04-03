#include<queue>
#include<iostream>
#include<cstring>
#include<functional>
#include<algorithm>
using namespace std;
int p[200005],ans[200005],st[200005],u,v,w,N,M,Q,K,t,s;
typedef pair<int,int>PII;
priority_queue<PII,vector<PII>,greater<PII>>heap;
struct mp
{
	int from,to,val,next;
} m[200005];
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
	while(heap.size())
	{
		int ver = heap.top().second;
		heap.pop();
		if(st[ver])continue;
		st[ver]=true;
		for(int i=p[ver]; i; i=m[i].next)
		{
			int j=m[i].to;
			if(ans[j]>ans[ver]+m[i].val)
			{
				ans[j]=ans[ver]+m[i].val;
				heap.push({ans[j],j});
			}
		}
	}
}
int main()
{
	memset(ans,0x3f,sizeof(ans));
	cin>>N>>M;
	for(int i=0; i<M; i++)
	{
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	cin>>K;
	for(int i=0; i<K; i++)
	{
		cin>>s;
		heap.push({0,s});
		ans[s]=0;
	}
	dist();
	cin>>Q;
	for(int i=0; i<Q; i++)
	{
		cin>>s;
		cout<<ans[s]<<"\n";
	}
}
