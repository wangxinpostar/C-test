#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    int n, x, y;
    string s;
    cin >> n;
    unordered_map<int, string> m;
    unordered_map<string, int> p;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> x >> y;
        m[x] = s;
        p[s]=y;
    }
    cin>>n;
    while(n--)
    {
        cin>>x;
        cout<<m[x]<<" "<<p[m[x]]<<"\n";
    }
    return 0;
}