#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n[200],i=0;
    int x;
    while(cin>>x&&x!=0)
    {
        n[i++]=x;
    }
    for(i--;i>=0;i--)
    {   
        cout<<n[i]<<" ";
    }
}