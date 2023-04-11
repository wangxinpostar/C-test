#include <iostream>
using namespace std;
int months[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool check(int year, int month, int day)
{
    if (month == 0 || month > 12)
        return false;
    if (day == 0)
        return false;
    if (month != 2)
    {
        if (day > months[month])
            return false;
    }
    else
    {
        int leap = year % 100 && year % 4 == 0 || year % 400 == 0;
        if (day > 28 + leap)
            return false;
    }
    return true;
}
int main()
{
    int a, b, c;
    scanf("%d/%d/%d", &a, &b, &c);

    for (int i = 19610101; i <= 20591231; i++)
    {
        int year = i / 10000;
        int month = i / 100 % 100;
        int day = i % 100;

        if (check(year, month, day))
        {
            if (a == year % 100 && b == month && day == c ||
                a == month && b == day && c == year % 100 ||
                a == day && b == month && c == year % 100)
                printf("%02d-%02d-%02d\n", year, month, day);
        }
    }
}