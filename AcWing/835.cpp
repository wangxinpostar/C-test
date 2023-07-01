#include <iostream>
using namespace std;
const int N = 100005;
int son[N][26], cnt[N], idx;
char str[N];
void insert(char *str)
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u])
            son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}
int query(char *str)
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u])
            return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        char c;
        cin >> c >> str;
        if (c == 'I')
            insert(str);
        if (c == 'Q')
            cout << query(str) << '\n';
    }
}