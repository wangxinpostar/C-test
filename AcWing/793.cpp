#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int N = 1e5 + 5;
int A[N], B;
vector<int> C;
string a;
void mul(int A[], int B)
{
    for (int i = 0, t = 0; i < a.size() || t; i++)
    {
        t += A[i] * B;
        C.push_back(t % 10);
        t /= 10;
    }
}
int main()
{
    cin >> a >> B;
    int k = 0;

    for (int i = a.size() - 1; i >= 0; i--)
        A[k++] = a[i] - '0';

    mul(A, B);

    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
    for (int i = C.size() - 1; i >= 0; i--)
        cout << C[i];
}
