#include <iostream>
using namespace std;
int main()
{
  long long a,b,n;
  cin>>a>>b>>n;
  long long k=5*a+2*b;
  long long ans=(n/k)*7;
  long long s=n%k;
  for(int i=0;i<5,s>0;i++)
  {
    s-=a;
    ans+=1;
  }
  for(int i=0;i<2,s>0;i++)
  {
    s-=b;
    ans+=1;
  }
  cout<<ans;
  return 0;
}