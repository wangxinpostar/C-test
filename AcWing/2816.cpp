#include <iostream>
using namespace std;
int a[100005], b[100005];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (a[i] != b[j])
            j++;
        else
            i++, j++;
    }
    if (i == n)
        cout << "Yes";
    else
        cout << "No";
}