#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int m[10];
bool is(int x)
{
	while(x)
	{
		if(m[x%10])return false;
		m[x%10]++;
		x/=10;
	}
	return true;
}
int main()
{
	int a,b,c,t=0;
	cin>>a>>b>>c;
	if(a==0||b==0||c==0)
	{
		cout<<"No!!!\n";
		return 0;
	}
	for(int i=100; i<=999; i++)
	{
		int s=i*b*c;
		int B=s/a/c;
		int C=s/a/b;
		memset(m+1,0,sizeof(m));
		if(B>100&&B<=999&&C>100&&C<999&&is(i)&&is(B)&&is(C))
		{
			for(int i=1; i<=9; i++)
			{
				if(m[i]>1||m[i]==0)
				{
					continue;
				}
			}
			cout<<i<<" "<<B<<" "<<C<<"\n";
			t++;
		}
	}
	if(!t)
	{
		cout<<"No!!!\n";
		return 0;
	}
	else
	{
		return 0;
	}
}
