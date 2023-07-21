#include <iostream>
using namespace std;
const int N = 100;
int stack[N], top = -1, idx;
char str[N];
void push(int x)
{
    stack[++top] = x;
    idx++;
}
void pop(int x)
{
    top--;
}
int query()
{
    return stack[top];
}
bool empty()
{
    return top <= -1;
}
int main()
{
    cin >> str;
    for (int i = 0; str[i]; i++)
    {
        if (empty())
            push(str[i]);
        else
        {
            if (query() == 'a' && str[i] == 'b')
                top--;
            else
                push(str[i]);
        }
    }
    if (empty())
        puts("Good");
    else
        puts("Bad");
}