#include <bits/stdc++.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <queue>
#include <deque>
using namespace std;
void build(string in,string af)
{
    if(in.size())
    {
        char ch=af[af.size()-1];
        cout<<ch;
        int k=in.find(ch);
        build(in.substr(0,k),af.substr(0,k));
        build(in.substr(k+1),af.substr(k,in.size()-k-1));
    }
}
int main()
{
    string info,affo;
    cin>>info>>affo;
    build(info,affo);
}