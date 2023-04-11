#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <deque>
#include <queue>
#include <functional>
#include <unordered_map>
#include <unordered_set>
using namespace std;
int n;
void mysort(int nums[], int l, int r)
{
    int begin = l, end = r;
    int key = l;
    if (l >= r)
    {
        return;
    }
    while (l < r)
    {
        while (nums[r] >= nums[key] && l < r)
        {
            r--;
        }
        while (nums[l] <= nums[key] && l < r)
        {
            l++;
        }

        swap(nums[l], nums[r]);
    }
    swap(nums[key], nums[l]);
    mysort(nums, begin, l - 1);
    mysort(nums, l + 1, end);
}
int main()
{
    cin >> n;
    int *m = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> m[i];
    }
    mysort(m, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << m[i] << " ";
    }
    delete[] m;
}