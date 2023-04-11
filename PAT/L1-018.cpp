#include <iostream>
#include <string>
using namespace std;
int main()
{
    char s[100];
    int h, m;
    scanf("%s", s);
    if (s[0] != '0')
        h = (s[0] - '0') * 10 + s[1] - '0';
    else
        h = s[1] - '0';
    if (s[3] != '0')
        m = (s[3] - '0') * 10 + s[4] - '0';
    else
        m = s[4] - '0';
    if (h >= 0 && h < 12 || h == 12 && m == 0)
        printf("Only %s.  Too early to Dang.\n", s);
    else
    {
        if (m != 0)
            for (int i = 0; i < (h % 12) + 1; i++)
                printf("Dang");
        else
            for (int i = 0; i < ((h - 1) % 12) + 1; i++)
                printf("Dang");
        printf("\n");
    }
    return 0;
}