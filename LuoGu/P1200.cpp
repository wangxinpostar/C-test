#include<vector>
#include<iostream>
#include<string>
#include<deque>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<map>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    string s,t;
    cin>>s>>t;
    int a=1,b=1;
    for(char i:s)
    {
        a*=i-'A'+1;
    }
    for(char i:t)
    {
        b*=i-'A'+1;
    }
    if(a%47==b%47)
    {
        cout<<"GO";
    }
    else
    {
        cout<<"STAY";
    }
}