#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement1(vector<int> &nums)
{
    // Brute Force Way O(n2)
    vector<int> ans;
    int reqTimes = nums.size() / 3;
    for (int i = 0; i < nums.size(); i++)
    {
        if (ans.size() == 0 || ans[0] != nums[i])
        {
            int count = 0;
            for (int j = 0; j < nums.size(); j++)
            {
                if (nums[j] == nums[i])
                    count++;
                if (count > reqTimes)
                {
                    ans.push_back(nums[i]);
                    break;
                }
            }
        }
        if (ans.size() == 2)
        {
            break;
        }
    }
    return ans;
}

vector<int> majorityElement2(vector<int> &nums)
{
    // Better O(n) S(n)
    // IN two pass
    map<int, int> mpp;
    for (int i = 0; i < nums.size(); i++)
    {
        mpp[nums[i]]++;
    }
    vector<int> ans;
    int mini = nums.size() / 3;
    for (auto it : mpp)
    {
        if (it.second > mini)
            ans.push_back(it.first);
    }
    return ans;

    // in one Pass
    // vector<int> ans;
    // map<int,int> mpp;
    // int mini=nums.size()/3+1;
    // for(int i=0;i<nums.size();i++){
    //   mpp[nums[i]]++;
    //   if(mpp[nums[i]]==mini) ans.push_back(nums[i]);
    //   if(ans.size()==2) break;
    // }
    // return ans;
}

vector<int> majorityElement3(vector<int> &nums)
{
    // Optimal O(n) ,using derived Moore Algo.
    int cnt1 = 0, cnt2 = 0, el1 = INT_MIN, el2 = INT_MIN;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        if (cnt1 == 0 && nums[i] != el2)
        {
            cnt1 = 1;
            el1 = nums[i];
        }
        else if (cnt2 == 0 && nums[i] != el1)
        {
            cnt2 = 1;
            el2 = nums[i];
        }
        else if (el1 == nums[i])
            cnt1++;
        else if (nums[i] == el2)
            cnt2++;
        else
        {
            cnt1--, cnt2--;
        }
    }

    int c1 = 0, c2 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == el1)
            c1++;
        if (nums[i] == el2)
            c2++;
    }
    int mini = nums.size() / 3;
    if (c1 > mini)
        ans.push_back(el1);
    if (c2 > mini)
        ans.push_back(el2);
    return ans;
}

int main()
{
    vector<int> v = {1, 2, 2, 4, 1, 2, 1, 1};
    vector<int> ans = majorityElement2(v);
    for (auto it : ans)
        cout << it;
    return 0;
}