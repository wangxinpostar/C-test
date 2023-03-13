#include<iostream>
#include<unordered_set>
using namespace std;
#define int long long
signed main()
{
    unordered_set<int>p;
    int a,b,n,k=0;
    cin>>n;
    while(n--)
    {
        cin>>b;
        p.insert(abs(a-b));
        a=b;
        k++;
    }
    for(int i=1;i<k;i++)
    {
        if(!p.count(i))
        {
            cout<<"Not jolly";
            return 0;
        }
    }
    cout<<"Jolly";
}