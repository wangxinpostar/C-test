#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int ans = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] != '1' && ans % 2 == 0 || s[i] == '1' && ans % 2 != 0)
        {
            ans++;
        }
    }
    cout << ans;
}