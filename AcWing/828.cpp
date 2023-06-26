#include <iostream>
using namespace std;
const int N = 1e6;
int stack[N], top = -1, idex;
void push(int x)
{
    stack[++top] = x;
}
void pop()
{
    top--;
}
bool empty()
{
    if (top <= -1)
        return true;
    else
        return false;
}
int query()
{
    return stack[top];
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