#include<bits/stdc++.h>
using namespace std;
void solve(int n)
{
    int x=1;
    while((1<<x)<=n)
    {
        x++;
    }
    x--;
    if(x==0)
    {
        cout<<"2(0)";
    }
    if(x==1)
    {
        cout<<"2";
    }
    if(x>1)
    {
        cout<<"2(";
        solve(x);
        cout<<")";
    }
    if((1<<x)!=n)
    {
        cout<<"+";
        solve(n-(1<<x));
    }
    return;
}
int main()
{
    int n;
    cin>>n;
    solve(n);
    return 0;
}