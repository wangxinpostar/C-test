#include<iostream>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int ans=n;
    while(n>=k)
    {
        ans+=n/k;
        n=n/k+n%k;
    }
    cout<<ans;
}