#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d;
    char x;
    cin>>a>>x>>b>>c>>x>>d;
    cout<<b*d/__gcd(a*c,b*d)<<" "<<a*c/__gcd(a*c,b*d);
    return 0;
}