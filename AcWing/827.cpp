#include <iostream>
using namespace std;
const int N = 1e6;
int e[N], l[N], r[N], idex;
void add(int k, int x)
{
    e[idex] = x;
    r[idex] = r[k];
    l[idex] = k;
    l[r[k]] = idex;
    r[k] = idex++;
}
void remove(int k)
{
    l[r[k]] = l[k];
    r[l[k]] = r[k];
}
int main()
{
    int m;
    cin >> m;
    r[0] = 1;
    l[1] = 0;
    idex = 2;
    while (m--)
    {
        string s;
        int k, x;
        cin >> s;
        if (s == "L")
        {
            cin >> x;
            add(0, x);
        }
        else if (s == "R")
        {
            cin >> x;
            add(l[1], x);
        }
        else if (s == "IL")
        {
            cin >> k >> x;
            add(l[k + 1], x);
        }
        else if (s == "IR")
        {
            cin >> k >> x;
            add(k + 1, x);
        }
        else if (s == "D")
        {
            cin >> k;
            remove(k + 1);
        }
    }
    for (int i = r[0]; i != 1; i = r[i])
        cout << e[i] << " ";
}