#include<bits/stdc++.h>
using namespace std;
void f(int n)
{
    int x=1;
    while ((1<<x)<=n)
    {
        x++;
    }
    x--;
    if(x==0)cout<<"2(0)";
    if(x==1)cout<<"2";
    if(x>1)
    {
        cout<<"2(";
        f(x);
        cout<<")";
    }
    if((1<<x)!=n)
    {
        cout<<"+";
        f(n-(1<<x));
    }
}
int main()
{
    int n;
    cin>>n;
    f(n);
}