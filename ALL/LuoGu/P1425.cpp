#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d; 
    int ans=(c*60+d)-(a*60+b);
    cout<<ans/60<<" "<<ans%60;
}