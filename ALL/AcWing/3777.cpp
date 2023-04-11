#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int n,m;
void doing(char& x)
{
        if(x=='W')
        {
            x='B';
        }
        else
        {
            x='W';    
        }
}
bool is(string s,char c)
{
    vector<int> res;
    for (int i = 0; i+1 < m; i ++ )
    {
        if(s[i]!=c)
        {
            res.push_back(i);
            doing(s[i]);
            doing(s[i+1]);
        }
    }
    if(s[0]==s[m-1])
    {
        cout<<res.size()<<"\n";
        for(auto i:res)
        {
            cout<<i+1<<" ";
        }
        if(res.size())
        cout<<"\n";
        return true;
    }
    return false;
}
int main()
{

    cin>>n;
    while (n -- )
    {
        string s;
        cin>>m>>s;
        if(!is(s,'W')&&!is(s,'B'))
        {
            cout<<-1<<"\n";
        }
    }
}