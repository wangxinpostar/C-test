#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

typedef unsigned long long ull;
const int N = 100010, P = 131;
unordered_set<ull> h;
int main()
{
    int n;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        ull k = 0;
        for (int j = 0; j < s.size(); j++)
        {
            k = k * P + s[j];
        }
        h.insert(k);
    }

    cout << h.size();
}