#include <bits/stdc++.h>
using namespace std;
bool p[100000010];
int m[100000010], t = 1;
void s(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!p[i])
        {
            m[t++]=i;
        }
        for(int j=1;j<t&&i*m[j]<=n;j++)
        {
            p[i*m[j]]=1;
            if(i%m[j]==0)break;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int N, M;
    cin >> N >> M;
    s(N);
    for (int i = 0; i < M; i++)
    {
        cin >> N;
        cout << m[N] << "\n";
    }
}