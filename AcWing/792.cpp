#include <iostream>
#include <string>
#include <cmath>
using namespace std;
const int N = 1e5 + 5;
int A[N], B[N], C[N];
string a, b;
bool cmp(int A[], int B[])
{
    for (int i = N - 10; i >= 0; i--)
    {
        if (A[i] > B[i])
            return true;
        if (B[i] > A[i])
            return false;
    }
    return true;
}
void sub(int A[], int B[])
{
    for (int i = 0, t = 0; i < N; i++)
    {
        t = A[i] - t;
        t -= B[i];
        C[i] += (t + 10) % 10;
        t < 0 ? t = 1 : t = 0;
    }
}
int main()
{
    cin >> a >> b;
    int k = 0;
    for (int i = a.size() - 1; i >= 0; i--)
        A[k++] = a[i] - '0';
    k = 0;
    for (int i = b.size() - 1; i >= 0; i--)
        B[k++] = b[i] - '0';

    if (cmp(A, B))
        sub(A, B);
    else
        sub(B, A), cout << '-';

    int j = N - 10;

    while (C[j] == 0 && j > 0)
        j--;
    for (j; j >= 0; j--)
        cout << abs(C[j]);
}
