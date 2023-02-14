#include<bits/stdc++.h>
using namespace std;
bool cmp(string a,string b)
{
    return a+b>b+a;
}
int main()
{
    int n;
    string m[50];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>m[i];
    }
    sort(m,m+n,cmp);
    for(int i=0;i<n;i++)
    {
        cout<<m[i];
    }
}