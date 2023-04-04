#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    long long c=0,z=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            long long k=(n-i+1)*(m-j+1);
            if(i==j)
            {
                z+=k;
            }
            else
            {
                c+=k;
            }
        }
    }
    cout<<z<<" "<<c;
    return 0;
}