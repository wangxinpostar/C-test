#include <iostream>
#include <set>
using namespace std;
int main()
{
    set<int> m;
    int n, k;
    cin >> n;
    while (n--)
    {
        cin >> k;
        m.insert(k);
    }
    cout<<m.size()<<"\n";
    for (int i : m)
    {
        cout << i << " ";
    }
}