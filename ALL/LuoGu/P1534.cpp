#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b,ans=0,sum=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        ans+=a+b-8;
        sum+=ans;
    }
    cout<<sum;
    return 0;
}