#include <iostream>
#include <unordered_map>
using namespace std;
int ans[10000];
int main()
{
    unordered_map<int, string> m;
    m.insert({0, "ling"});
    m.insert({1, "yi"});
    m.insert({2, "er"});
    m.insert({3, "san"});
    m.insert({4, "si"});
    m.insert({5, "wu"});
    m.insert({6, "liu"});
    m.insert({7, "qi"});
    m.insert({8, "ba"});
    m.insert({9, "jiu"});
    int n, t = 0;
    cin >> n;
    if (n < 0)
    {
        cout << "fu ";
        n = -n;
    }
    if (n == 0)
    {
        cout << m[0] << "\n";
    }
    while (n)
    {
        ans[t++] = n % 10;
        n /= 10;
    }
    for (int i = t - 1; i >= 0; i--)
    {
        if (i != 0)
            cout << m[ans[i]] << " ";
        else
            cout << m[ans[i]] << "\n";
    }
}