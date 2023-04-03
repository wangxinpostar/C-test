#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    double n,m=2;
    long long t=0;
    cin>>n;
    while(n>0)
    {
        n-=m;
        m*=0.98;
        t++;
    }
    cout<<t;
}