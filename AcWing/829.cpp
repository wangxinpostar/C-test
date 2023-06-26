#include <iostream>
using namespace std;
const int N = 1e6;
int queue[N], front = 0, top = -1;
void push(int x)
{
    queue[++top] = x;
}
void pop()
{
    front++;
}
bool empty()
{
    if (front > top)
        return true;
    else
        return false;
}
int query()
{
    return queue[front];
}
int main()
{
    int m;
    cin >> m;
    while (m--)
    {
        string s;
        int x;
        cin >> s;
        if (s == "push")
            cin >> x, push(x);
        else if (s == "pop")
            pop();
        else if (s == "empty")
            empty() ? cout << "YES\n" : cout << "NO\n";
        else if (s == "query")
            cout << query() << '\n';
    }
}