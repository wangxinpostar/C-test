#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <cmath>
using namespace std;
double a,b,c,d;
int k;
double fc(double x)
{
     return (a*x*x*x+b*x*x+c*x+d)/100.00;
}
int main()
{
    cin>>a>>b>>c>>d;
    for(int i=-100;i<100;i++)
    {
        double l=i;
        double r=i+1;
        if(fc(l)==0.00)
        {
            printf("%.2f ",l);
            k++;
        }
        if(fc(l)*fc(r)<0)
        {
            while(r-l>=0.001)
            {
                double m=(r+l)/2.000;
                if(fc(l)*fc(m)>=0.00)
                {
                    l=m;
                }
                else
                {
                    r=m;
                }
            }
            printf("%.2f ",l);
            k++;
            if(k==3)
            return 0;
        }
    }
}