#include<iostream>
using namespace std;
typedef long long ll;
ll qmi(ll x,ll n,ll mod)
{
    ll res=1;
    while(n)
    {
        if(n&1)res=res*x%mod;
        x=x*x%mod;
        n>>=1;
    }
    return res%mod;
}
int main()
{
    ll x,n,mod;
    cin>>x>>n>>mod;
    printf("%lld^%lld mod %lld=%lld",x,n,mod,qmi(x,n,mod));
}