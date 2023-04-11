#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,ans=0;
    cin>>n;
    int *p=new int [n];
    for(int i=0;i<n;i++)
    cin>>p[i];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(p[j]>p[j+1])
            {
                swap(p[j],p[j+1]);
                ans++;
            }
        }
    }
    delete p;
    cout<<ans;
}