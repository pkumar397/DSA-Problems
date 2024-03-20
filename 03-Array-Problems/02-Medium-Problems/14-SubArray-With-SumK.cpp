#include <bits/stdc++.h>
using namespace std;

// Brute Force:
int subarraySum1(vector<int> &nums, int k)
{
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            sum += nums[j];
            if (sum == k)
                cnt++;
        }
    }
    return cnt;
}

// Optimal O(n) S(n) using hashmap and prefix sum:
int subarraySum2(vector<int> &nums, int k)
{
    map<int, int> mpp;
    int cnt = 0;
    mpp[0] = 1;
    int pre = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        pre += nums[i];
        int req = pre - k;
        if (mpp.find(req) != mpp.end())
            cnt += mpp[req];
        mpp[pre]++;
    }
    return cnt;
}
int main()
{
    vector<int> v = {3, -3, 1, 1, 1, 1, 2};
    int ans = subarraySum2(v, 3);
    cout << ans;
    return 0;
}