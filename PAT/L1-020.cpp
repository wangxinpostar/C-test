#include <iostream>
#include <unordered_set>
using namespace std;
string ans[100010];
int main()
{
    unordered_set<string> s, t;

    int n, T = 0;
    cin >> n;
    while (n--)
    {
        int m;
        cin >> m;
        if (m == 1)
        {
            string x;
            cin >> x;
            continue;
        }
        for (int i = 0; i < m; i++)
        {
            string x;
            cin >> x;
            s.insert(x);
        }
    }
    int p = 1;
    cin >> n;
    while (n--)
    {
        string x;
        cin >> x;
        if (!s.count(x) && !t.count(x))
        {
            t.insert(x);
            ans[T++] = x;
            p = 0;
        }
    }
    if (p)
    {
        cout << "No one is handsome\n";
    }
    else
    {
        for (int i = 0; i < T; i++)
        {
            cout << ans[i] << ((i == T - 1) ? "\n" : " ");
        }
    }
}