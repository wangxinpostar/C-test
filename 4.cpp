#include <cstdio>
#include <cctype>
#include <vector>
#include <cstring>
#include <algorithm>
#define maxn 2333
using namespace std;
char buf[maxn];
int n;
vector<int> a, b;
int main() {
    scanf("%d%s", &n, buf);
    for(int i = 0, len = strlen(buf); i < len; i++) { // 简单的按位读入
        if(buf[i] >= '0' && buf[i] <= '9') a.push_back(buf[i] - '0');
        else a.push_back(islower(buf[i]) ? buf[i] - 'a' + 10 : buf[i] - 'A' + 10);
    }
    b = a; // 将a copy到b里。
    reverse(a.begin(), a.end()); // 反转a。
    if(a == b) return puts("STEP=0"), 0; //反转后相等即为回文
    for(int ans = 1; ans <= 30; ans++) {
        for(int i = 0, siz = a.size(); i < siz; i++) {
            a[i] += b[i]; // 加法
            if(i != siz - 1) a[i + 1] += a[i] / n; // 处理进位
            else if(a[i] >= n) a.push_back(a[i] / n);
            a[i] %= n;
        }
        b = a;
        reverse(b.begin(), b.end());
        if(a == b) return printf("STEP=%d", ans), 0; // 判回文
    }
    return puts("Impossible!"), 0;
}