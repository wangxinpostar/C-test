#include<vector>
#include<cmath>
#include<iostream>
using namespace std;
int main()
{
    int m[15]={0};
    int d,ans=0;
    for(int i=0;i<10;i++)
    {
        cin>>m[i];
        m[i]-=30;
    }
    cin>>d;
    for(int i=0;i<10;i++)
    {
        if(m[i]<=d)
        ans++;
    }
    cout<<ans;
}