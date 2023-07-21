#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int m[4];
    cin >> m[0] >> m[1] >> m[2];
    sort(m, m + 3);
    cout << m[0] << "->" << m[1] << "->" << m[2];
}