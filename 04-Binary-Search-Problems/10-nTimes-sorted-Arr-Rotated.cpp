#include <bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> &nums)
{
    // Write your code here.
    int low = 0, high = nums.size() - 1;
    int ans = INT_MAX;
    int index = 0;
    if (nums[low] <= nums[high])
        return 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        // Check which half is sorted
        // left half sorted
        if (nums[mid] >= nums[low])
        {
            if (ans >= nums[low])
            {
                index = low;
                ans = nums[low];
            }
            low = mid + 1;
        }
        else
        {
            if (ans >= nums[mid])
            {
                index = mid;
                ans = nums[mid];
            }
            high = mid - 1;
        }
    }
    return index;
}
int main()
{
    vector<int> v = {4, 5, 6, 1, 2, 3}; // so index of minimum element in the sorted rotated arr will be ans
    cout << findKRotation(v);
    return 0;
}