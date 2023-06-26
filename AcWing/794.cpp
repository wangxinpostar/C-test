#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int N = 1e5 + 5;
int A[N], B;
vector<int> C;
string a;
int div(int A[], int B)
{
    int r = 0;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        r = r * 10 + A[i];
        C.push_back(r / B);
        r %= B;
    }
    return r;
}
int main()
{
    cin >> a >> B;
    int k = 0;
    for (int i = a.size() - 1; i >= 0; i--)
        A[k++] = a[i] - '0';
    int r = div(A, B);

    int j = 0;
    while (j < a.size() - 1 && C[j] == 0)
        j++;
    for (j; j < C.size(); j++)
        cout << C[j];
    cout << endl
         << r;
}