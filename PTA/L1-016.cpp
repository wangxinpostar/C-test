#include <cstring>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    unordered_map<int, char> m;
    int d[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    m.insert({0, '1'});
    m.insert({1, '0'});
    m.insert({2, 'X'});
    m.insert({3, '9'});
    m.insert({4, '8'});
    m.insert({5, '7'});
    m.insert({6, '6'});
    m.insert({7, '5'});
    m.insert({8, '4'});
    m.insert({9, '3'});
    m.insert({10, '2'});
    int n, p = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        int sum = 0;
        int q = 1;
        for (int j = 0; j < int(s.size() - 1); j++)
        {
            if (s[j] >= '0' && s[j] <= '9')
                sum += (s[j] - '0') * d[j];
            else
            {
                cout << s << "\n";
                p = 0;
                q = 0;
                break;
            }
        }
        if (m[sum % 11] != s[s.size() - 1] && q)
        {
            p = 0;
            cout << s << "\n";
        }
    }
    if (p)
        cout << "All passed\n";
}