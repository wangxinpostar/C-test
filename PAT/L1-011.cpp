#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int m[1000];
int main()
{
    string a,b;
    getline(cin,a);
    getline(cin,b);
    for(int i=0;i<b.size();i++)
    {
        m[b[i]]++;
    }
    for(int i=0;i<a.size();i++)
    {
        if(!m[a[i]])
        {
            cout<<a[i];
        }
    }
    cout<<"\n";
}