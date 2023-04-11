#include <iostream>
using namespace std;
int main()
{
    int a, b, sum = 0, j = 1;
    cin >> a >> b;
    for (int i = a; i <= b; i++)
    {
        if (j % 5 == 0)
        {
            printf("%5d\n", i);
            j = 0;
        }
        else
        {
            printf("%5d", i);
        }
        j++;
        sum += i;
    }
    if (j == 1)
    {
        printf("Sum = %d\n", sum);
    }
    else
    {
        printf("\nSum = %d\n", sum);
    }
}