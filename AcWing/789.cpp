#include <iostream>
using namespace std;
int n, q, m[100010];
int main()
{
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> m[i];

    while (q--)
    {
        int x;
        cin >> x;

        int l = 0, r = n - 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (m[mid] >= x)
                r = mid;
            else
                l = mid + 1;
        }
        if (m[l] != x)
            cout << "-1 -1" << endl;
        else
        {
            cout << l << " ";
            int l = 0, r = n - 1;
            while (l < r)
            {
                int mid = l + r + 1 >> 1;
                if (m[mid] <= x)
                    l = mid;
                else
                    r = mid - 1;
            }
            cout << l << endl;
        }
    }
}