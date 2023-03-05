#include <bits/stdc++.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <queue>
#include <deque>
#include<iostream>
using namespace std;
const int N = 1e5 + 10;
 
long long  a[N];
long long  b[N];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]<=b[i])
        {
            ans+=a[i];
            b[i]-=a[i];
            a[i]=0;
        }
        else
        {
            ans+=b[i];
            b[i]=0;
            a[i]-=b[i];
        }
        if(a[i+1]<=b[i])
        {
            ans+=a[i+1];
            b[i]-=a[i+1];
            a[i+1]=0;
        }
        else
        {
            ans+=b[i];
            a[i+1]-=b[i];
            b[i]=0;
        }
    }
    cout<<ans;
}