#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,ans=0,res=0,x,y=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        if(x>y)
        {
            ans++;
        }
        else
        {
            res=max(res,ans);
            ans=1;
        }
        y=x;
    }
    cout<<max(res,ans);
    return 0;
}