#include <iostream>
#include <cstring>
using namespace std;
int A[100005], B[100005], C[100005];
string a, b;
void add(int A[], int B[])
{
    for (int i = 0, t = 0; i < 100005; i++)
    {
        t += A[i];
        t += B[i];
        C[i] += t % 10;
        t /= 10;
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
    add(A, B);
    int j = 100000;
    while (C[j] == 0 && j > 0)
        j--;
    for (j; j >= 0; j--)
        cout << C[j];
}
