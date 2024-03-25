#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> nums, int target)
{
    int low = 0, high = nums.size() - 1;
    int lb = nums.size();
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] >= target)
        {
            lb = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return lb;
}
int upperBound(vector<int> nums, int target)
{
    int low = 0, high = nums.size() - 1;
    int ub = nums.size();
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] > target)
        {
            ub = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ub;
}
vector<int> searchRange(vector<int> &nums, int target)
{
    // Brute Force O(n)
    // int first=-1,last=-1;
    // for(int i=0;i<nums.size();i++){
    //     if(nums[i]==target) {
    //         if(first==-1) first=i;
    //         last=i;
    //     }
    // }
    // return {first,last};

    // Using Lower Bound and Upper bound (Better Approach) O(2logn)
    // int first=lowerBound(nums,target);
    // int second=upperBound(nums,target);
    // if(nums.size()==0) return {-1,-1};
    // if(first==nums.size() || nums[first]!=target) return {-1,-1};
    // return {first,second-1};

    // Using Pure BS O(log n)
    int low = 0, high = nums.size() - 1;
    int first = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
        {
            first = mid;
            high = mid - 1;
        }
        else if (nums[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    low = 0, high = nums.size() - 1;
    int last = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        // cout << mid;
        if (nums[mid] == target)
        {
            last = mid;
            low = mid + 1;
        }
        else if (nums[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return {first, last};
}

int main()
{

    vector<int> v = {1, 3, 4, 8, 8, 9};
    int target = 8;
    vector<int> ans = searchRange(v, target);
    cout << "First Occurance: " << ans[0] << " Second Occurance: " << ans[1];
    return 0;
}