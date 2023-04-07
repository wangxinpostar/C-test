#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>
#include <functional>
#include <cmath>
#include <unordered_map>
using namespace std;
int m[100][100], ans[100][100], t, N, M;
bool st[100][100];
typedef pair<int, int> pii;
void dist(int x, int y)
{
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<>> heap;
    heap.push({0, {x, y}});
    ans[x][y] = m[x][y];
    int d[] = {-1, 0, 1, 0, -1};
    while (heap.size())
    {
        pii ver = heap.top().second;
        heap.pop();
        int x1 = ver.first, y1 = ver.second;
        if (st[x1][y1])
            continue;
        st[x1][y1] = true;
        for (int i = 0; i < 4; i++)
        {
            int x2 = x1 + d[i];
            int y2 = y1 + d[i + 1];
            if (x2 >= 1 && x2 <= N && y2 >= 1 && y <= M && m[x2][y2] != -1)
            {
                if (ans[x2][y2] > ans[x1][y1] + m[x2][y2])
                {
                    ans[x2][y2] = ans[x1][y1] + m[x2][y2];
                    heap.push({ans[x2][y2], {x2, y2}});
                }
            }
        }
    }
}
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> N >> M;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                cin >> m[i][j];
            }
        }
        memset(ans, 0x3f, sizeof(ans));
        dist(1, 1);
        if (ans[N][M] >= 0x3f3f3f3f / 2)
            cout << "-1\n";
        else
            cout << ans[N][M] << "\n";
    }
    return 0;
}
// long long a[300000],p[300000], num,counter,n,q,x;
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0), cout.tie(0);
//     cin >> n;
//     for (long long i = 1; i <= n; i++)
//     {
//         cin >> a[i];
//     }
//     cin >> q;
//     for (long long i = 1; i <= q; i++)
//     {
//         cin >> x;
//         if (x == 1)
//         {
//             cin >> num;
//             counter++;
//         }
//         if (x == 2)
//         {
//             long long pos, k;
//             cin >> pos >> k;
//             if(p[pos]==counter)a[pos]+=k;
//             if(p[pos]<counter)
//             {
//                 a[pos]=num+k;
//                 p[pos]=counter;
//             }
//         }
//         if (x == 3)
//         {
//             long long pos;
//             cin>>pos;
//             if(p[pos]==counter)cout<<a[pos]<<"\n";
//             if(p[pos]<counter)
//             {
//                 cout<<num<<"\n";
//                 p[pos]=counter;
//                 a[pos]=num;
//             }

//         }
//     }
//     return 0;
// }