#include <iostream>
using namespace std;
int primes[1000005], cnt;
bool p[1000005];
void isprime(int n)
{
    p[1] = true;
    for (int i = 2; i <= n; i++)
    {
        if (!p[i])
            primes[cnt++] = i;
        for (int j = 0; primes[j] * i <= n; j++)
        {
            p[primes[j] * i] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    isprime(n);
    cout << cnt++;
}