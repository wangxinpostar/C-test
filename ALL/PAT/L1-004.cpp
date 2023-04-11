#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double x;
    cin >> x;
    cout << "Celsius = " << int(5 * (x - 32) / 9) << "\n";
    return 0;
}