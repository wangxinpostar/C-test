#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    if (scanf("%d", &n))
        printf("2^%d = %d\n", n, int(pow(2, n)));
}