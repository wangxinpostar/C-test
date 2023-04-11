#include <iostream>
#include <map>
using namespace std;
int main()
{
    map<int, int> m;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        m[s[i] - '0']++;
    }
    for (auto i : m)
    {
        cout << i.first << ":" << i.second << "\n";
    }
    return 0;
}