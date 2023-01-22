#include<bits/stdc++.h>
using namespace std;
long long k,ans;
stack<long long> s;
bool isou(long long x)
{
    if(x%2==0)
    {
        return true;
    }
    return false;
}
int main()
{
    int m,n;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        ans=0;
        cin>>n;
        for(int j=0;j<n;j++)
        {
            cin>>k;
            if(j==0)
            {
                s.push(k);
                continue;
            }
            if(!s.empty())
            {
                if(isou(s.top())==isou(k))
                {
                    s.top()*=k;
                    ans++;
                }
                else
                {
                    s.push(k);
                }  
            }
        }
        while(!s.empty())
        {
            s.pop();
        }
        cout<<ans<<endl;
    }
}