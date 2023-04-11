#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int p[10];
int main()
{
    for(int i=111;i<=333;i++)
    {
        memset(p,0,sizeof(p));
        int a=i,b=2*i,c=3*i,t=0;
        while(a)
        {
            p[a%10]++;
            a/=10;
        }
        while(b)
        {
            p[b%10]++;
            b/=10;
        }
        while(c)
        {
            p[c%10]++;
            c/=10;
        }
        for(int i:p)
        {
            if(i>1||p[0]!=0)
            t=1;
        }
        if(!t)
        cout<<i<<" "<<2*i<<" "<<3*i<<"\n";
    }
}