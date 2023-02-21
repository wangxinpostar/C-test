#include<bits/stdc++.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<deque>
#include<queue>
#include<set>
#include<map>
using namespace std;
int hou[100],zhong[100],id[100];
int n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>hou[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>zhong[i];
        id[zhong[i]]=i;
    }
    
}