#include <vector>
#include <iostream>
#include <string>
#include <deque>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    string s;
    int b = 0, g = 0;
    cin >> s;
    for (int i = 0; i < s.size() - 2; i++)
    {
        if (s[i] == 'b' || s[i + 1] == 'o' || s[i + 2] == 'y')
        {
            b++;
        }

        if ((i!=s.size() - 3)&&(s[i] == 'g' || s[i + 1] == 'i' || s[i + 2] == 'r' || s[i + 3] == 'l'))
        {
            g++;
        }
    }
    cout << b << "\n"
         << g;
}