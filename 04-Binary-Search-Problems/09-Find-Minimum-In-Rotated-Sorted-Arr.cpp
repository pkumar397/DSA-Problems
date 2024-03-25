#include <bits/stdc++.h>
using namespace std;
int findMin(vector<int> &nums)
{
    int low = 0, high = nums.size() - 1;
    int ans = INT_MAX;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        // Check which half is sorted
        // left half sorted
        if (nums[mid] >= nums[low])
        {
            ans = min(ans, nums[low]);
            low = mid + 1;
        }
        else
        {
            ans = min(ans, nums[mid]);
            high = mid - 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> v = {4, 5, 1, 2, 3};
    cout << findMin(v);
    return 0;
}