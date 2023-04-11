#include <bits/stdc++.h>
#include <map>
#include <deque>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int n;
string m;
vector<int> a, b;
bool hw(string s)
{
    string t = s;
    reverse(s.begin(), s.end());
    return t == s;
}
bool solve(int n, string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            a.push_back(s[i] - '0');
        }
        else
        {
            if (islower(s[i]))
            {
                a.push_back(s[i] - 'a' + 10);
            }
            else
            {
                a.push_back(s[i] - 'A' + 10);
            }
        }
    }
    b = a;
    reverse(a.begin(), a.end());
    for (int i = 1; i <= 30; i++)
    {
        int stl = a.size();
        for (int j = 0; j < stl; j++)
        {
            a[j] += b[j];
            if (j == stl - 1 && a[j] >= n)
            {
                a.push_back(a[j] / n);
            }
            else
            {
                a[j + 1] += a[j] / n;
            }
            a[j] %= n;
        }
        b = a;
        reverse(a.begin(), a.end());
        if (a == b)
        {
            cout << "STEP=" << i;
            return true;
        }
    }
    return false;
}
int main()
{
    cin >> n >> m;
    if (hw(m))
    {
        cout << "STEP=0";
    }
    else
    {
        if (!solve(n, m))
            cout << "Impossible!";
    }
}