#include <iostream>
using namespace std;
int main()
{
  string s="2022";
  int ans=0;
  for(char i:s)
  {
    ans*=9;
    ans+=i-'0';
  }
  cout<<ans;
  return 0;
}