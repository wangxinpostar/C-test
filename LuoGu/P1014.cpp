#include<algorithm>
#include<cmath>
#include<deque>
#include<queue>
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int m=(i*i+i)/2;
        if(m>=n)
        {
            if(i%2!=0)
            {
                cout<<m-n+1<<"/"<<i-(m-n);
            }
            else
            {
                cout<<i-(m-n)<<"/"<<m-n+1;
            }
            return 0;
        }
    }
}