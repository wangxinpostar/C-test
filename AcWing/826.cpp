#include <iostream>
using namespace std;
const int N = 1e6;
int e[N], ne[N], head = -1, idex = 0;
void headadd(int x)
{
    e[idex] = x;
    ne[idex] = head;
    head = idex++;
}
void add(int k, int x)
{
    e[idex] = x;
    ne[idex] = ne[k];
    ne[k] = idex++;
}
void remove(int k)
{
    ne[k] = ne[ne[k]];
}
int main()
{
    int m;
    cin >> m;
    while (m--)
    {
        char c;
        int k, x;
        cin >> c;
        if (c == 'H')
        {
            cin >> x;
            headadd(x);
        }
        else if (c == 'D')
        {
            cin >> k;
            if (k == 0)
                head = ne[head];
            else
                remove(k - 1);
        }
        else if (c == 'I')
        {
            cin >> k >> x;
            add(k - 1, x);
        }
    }
    for (int i = head; i != -1; i = ne[i])
        cout << e[i] << " ";
}