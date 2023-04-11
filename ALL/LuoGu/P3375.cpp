#include <functional>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <cmath>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;
char a[1000005], b[1000005];
int kmp[1000005];
int main()
{
    cin >> a >> b;
    kmp[0] = kmp[1] = 0;
    int len1 = strlen(a), len2 = strlen(b);
    int k = 0;
    for (int i = 1; i < len2; i++)
    {
        while (k && b[i] != b[k])
            k = kmp[k];
        kmp[i + 1] = b[i] == b[k] ? ++k : 0;
    }
    k = 0;
    for (int i = 0; i < len1; i++)
    {
        while (k && a[i] != b[k])
            k = kmp[k];
        k += a[i] == b[k] ? 1 : 0;
        if (k == len2)
            cout << i - len2 + 2 << "\n";
    }
    for (int i = 1; i <= len2; i++)
    {
        cout << kmp[i] << " ";
    }
}